#!/bin/bash

user_input=0
read useer_input

if [ $useer_input -lt 10 ]; then
    echo "It is 1 digit"
    exit 0; 
fi
if [ $useer_input -lt 100 ]; then
    echo "It is 2 digit"
    exit 0; 
fi

echo "It is 3 digits or more"
