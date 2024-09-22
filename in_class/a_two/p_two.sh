#!/bin/bash

# Initialize sum
sum=0

if [ "$#" -gt 9 ]; then
    echo "Too many arguments"
    exit 1
fi

for var in "$@"; do

    if [ "$var" -gt 10 ]; then
 
        sum=$((sum + var))
    fi
done

echo "Sum is: $sum"
