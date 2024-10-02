#!/bin/bash

hours=$(date +"%H")

if [[ hours -ge 18 ]];
then 

echo "Park now"

else 

echo "nah fam you are going to get a ticket"

fi 
