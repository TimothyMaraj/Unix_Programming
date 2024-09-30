#!/bin/bash



if [[ -z ${1} ]]; 
then 
    read -p "tell me your name: " name

    if [[ -z ${name} ]]; 
    then
        echo "Don't you have a name?" 
    else
        echo "Hello to you $name"
    fi
else 
    echo Hello to you ${1}
fi
