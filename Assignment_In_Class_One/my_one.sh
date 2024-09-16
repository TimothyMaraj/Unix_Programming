#!/bin/bash

car=35
van=55
suv=40
days=0
user_input=0






echo "Which vechile do you want? (car,van,suv)"
read user_input


if [[ "$user_input" != "car" && "$user_input" != "van" && "$user_input" != "suv" ]] ; then
    while [[ "$user_input" != "car" && "$user_input" != "van" && "$user_input" != "suv" ]]; do
        echo "Which vechile do you want? (car,van,suv)"
        read user_input 
    done
fi


echo "How many days?"
read days

if [ "$user_input" == "car" ] ; then
    echo $(expr $car \* $days)
fi