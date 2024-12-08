#!/bin/sh
 
component_file_h=./component.h

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

name=$2
upp_case=$(echo $name | tr a-z A-Z)

case $1 in
    "add")
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        cp -r ./.dummy ./$name
        mv ./$name/dummy.h ./$name/$name.h
        sed -i "s/dummy/$name/g" $name/$name.h
        sed -i "s/DUMMY/${upp_case}/g" $name/$name.h

        sed -i "/#endif \/\/ !__RACEUP_BOARD_COMPONENT__/i\
        #ifdef MAX_${upp_case}S \n#include \"./${name}/${name}.h\"\n#endif \/\/!${upp_case}S"\
        "$component_file_h"
        ;;
    "del")
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        rm -rf ./$name
        sed -i "/#ifdef MAX_${upp_case}S/d" "$component_file_h"
        sed -i "/#include \".\/${name}\/${name}.h\"/d" "$component_file_h"
        sed -i "/#include \".\/${name}\/${name}.h\"/d" "$component_file_h"
        sed -i "/#endif \/\/!${upp_case}S/d" "$component_file_h"
        ;;
    "delall")
        cmps=$(./component_manager.sh lst)
        for item in $cmps; do
            ./component_manager.sh del $item
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
