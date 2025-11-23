#!/bin/bash


buildApp(){
    cmake -B ./build
}

deletebuildDir(){
    rm -rfv ./build
}

makeApp(){
    cmake --build ./build
}

runApp(){
    ./bin/tetris
}

while true; do
    read -p "Enter command: " task

    if [[ $task == "r" ]]; then
        runApp
    elif [[ $task == "b" ]]; then
        buildApp
    elif [[ $task == "m" ]]; then
        makeApp
    elif [[ $task == "d" ]]; then
        deletebuildDir
    elif [[ $task == "c" ]]; then
        break
    fi
done
