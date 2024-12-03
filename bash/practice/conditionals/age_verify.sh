#!/bin/bash

read -p "You want a beer?: " ui

if [[ $ui == "yes" ]];
then

    read -p "remind me ... how old are you again? " age

    if [[ $age -ge 21 ]]; 
    then
        echo "nice ... here you go"
    else
        echo "come on man ... you still have ur your baby teeth lol"
    fi

else
    echo "ur're pretty lame"

fi