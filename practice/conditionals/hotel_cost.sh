#!/bin/bash

echo "Let's calculate the cost of your visit"

read -p " how many nights? " nights
read -p " how much per night? " pernight

cost=$( expr $nights \* $pernight )

echo " it will cost: $cost "

if [[ $cost -ge 1000 && $nights -lt 10 ]]; 
then

echo "Wow thats expesnive!!!"

fi