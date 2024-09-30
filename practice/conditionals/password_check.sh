#!/bin/bash


password="a"

echo "super duper password checker"

read -p  "Enter in username: " uname

read -p "Enter in password: " upassword

counter=1

while [[ $counter -ne 3 && "$upassword" != "$password" ]]
do 

    read -p "Enter in password: " upassword

    ((counter++))

done

if [[ $counter -eq 3 && "$upassword" != "$password" ]];
then

echo "better luck next time"

else 

    if [[ $upassword == $password ]];
    then

    echo "login success! welcome $uname"

    fi

fi
