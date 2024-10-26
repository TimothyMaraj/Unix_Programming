#!/bin/bash

n=$(($RANDOM %10 +1 ))
n2=$(($RANDOM %11+10 ))


total=$((n2-n))

for num in { 0 .. $total}
do 

rand=$RANDOM

if test $((rand % 2)) -eq 0
then 

    echo $rand

fi 


done