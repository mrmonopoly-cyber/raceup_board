#!/bin/sh
 
component_file_h=./component.h
component_file_c=./component.c

help() {
    echo "usage: $0 [command] \<args\>";
    echo -e "command":
    echo -e "\t add: add a new component given a name as args"
    echo -e "\t del: delete an existing component given a name as args if exist, else do nothing"
    echo -e "\t delall: delete all existing components"
    echo -e "\t lst: list all existing components"
}

if [ ! -f ./component.h -o ! -f ./component_manager.sh -o ! -d ./.dummy  ]; then
    echo "run the script inside of the raceup_board/components directory"
    exit -1
fi

case $1 in
    "add")
        name=$2
        upp_case=$(echo $name | tr a-z A-Z)
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        cp -r ./.dummy ./$name
        mv ./$name/dummy.h ./$name/$name.h
        mv ./$name/dummy.c ./$name/$name.c
        sed -i "s/dummy/$name/g" $name/$name.h
        sed -i "s/DUMMY/${upp_case}/g" $name/$name.h
        sed -i "s/dummy/$name/g" $name/$name.c

        sed -i "s/enum COMPONENT_INDEX {/&\n\\t$upp_case,/" "$component_file_h"

        sed -i "/enum COMPONENT_INDEX {/i #include \"./$name/$name.h\"" "$component_file_h"
        sed -i "/}comps;/i component_$name $name;" "$component_file_h"


        sed -i "/default:/i case ${upp_case}: return init_new_${name}_component\(&comp->comps.$name\);" "$component_file_c"

        ;;
    "del")
        name=$2
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        rm -rf ./$name
        ;;
    "delall")
        cmps=$(./component_manager.sh lst)
        for item in $cmps; do
            rm -rf $item
        done
        ;;
    "lst") 
        /bin/ls -d */ 2>/dev/null | cut -d'/' -f1
        ;;
    *)
        help;
        exit 0;
        ;;
esac
