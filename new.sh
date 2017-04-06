SCRIPT=$(basename "$0")

help() {
cat <<EOF
Usage:
  $SCRIPT [options]
  $SCRIPT -h | --help

Options:
  --cpp                          Create a solution using C++.(Default)
  -s --swift                     Create a solution using Swift.
  -c                             Create a solution using C.
  -h --help                      Show this help.
EOF
}

if [ $# == 0 ]; then
    echo "Please input a new folder's name."
    help
    exit 1
fi

if [ $# == 1 ]; then
    if [ ${1:0:1} == "-" ]||[ ${1:0:2} == "--" ]; then
        help
        exit 1
    fi
    mkdir "$1"
    cd "$1"
    code solution.cpp
    cd ..
else
	case $1 in
        -cpp)
            mkdir "$2"
            cd "$2"
            code solution.cpp
            cd ..
            ;;
        -s|--swift)
            mkdir "$2"
            cd "$2"
            code solution.swift
            cd ..
            ;;
        -c)
            mkdir "$2"
            cd "$2"
            code solution.c
            cd ..
            ;;
        *)
            help
            exit 1
            ;;
    esac
fi