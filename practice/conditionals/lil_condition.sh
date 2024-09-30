#!/bin/bash

echo Are ${1} and ${2} equal?

if [[ "$1" == "$2" ]];
then
    echo "yes, they are equal"
else
    echo not equal!!!! ; 

fi

