#!/bin/sh

component_file=./component.h

help() {
    echo "usage: $0 [command] \<args\>";
    echo -e "command":
    echo -e "\t add: add a new component given a name as args"
    echo -e "\t del: delete an existing component given a name as args if exist, else do nothing"
    echo -e "\t lst: list all existing components"
}

if [ ! -f ./component.h -o ! -f ./component_manager.sh -o ! -d ./.dummy  ]; then
    echo "run the script inside of the raceup_board/components directory"
    exit -1
fi

case $1 in
    "add")
        name=$2
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        cp -r ./.dummy ./$name
        mv ./$name/dummy.h ./$name/$name.h
        sed -i "s/dummy/$name/g" $name/$name.h

        sed -i "/typedef union RaceupBoardComponent {/i #include \"./$name/$name.h\"" "$component_file"
        sed -i "/}RaceupBoardComponent;/i component_$name $name;" "$component_file"
        ;;
    "del")
        name=$2
        if [ -z $name ]; then
            echo "invalid input name, name must be non empty"
            exit -1
        fi
        rm -rf ./$name
        ;;
    "lst") 
        /bin/ls -d */ 2>/dev/null | cut -d'/' -f1
        ;;
    *)
        help;
        exit 0;
        ;;
esac
