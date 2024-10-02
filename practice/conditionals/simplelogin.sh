#!/bin/bash


uname_array=( "alt" "night" "brazil" )
password_array=( "nate" "sight" "sprite" )
echo "Login Page"

read -p "Enter UserName: " uname

found=false



for item in ${uname_array[@]}
do

if [[ $item == $uname ]]; 
then
    found=true
    break
fi

done


if [[ $found == true ]];  # have to check if the boloean is true so this becomes arbitrary
then 

    echo "You're good "

    read -p "Enter in your Password: " upass
    found2=false

    for i in ${password_array[@]} # looping thru, have to do each element in array by using @, could we use ? like array[*]
    do

        if [[ $i == $upass ]]; 
        then 

            found2=true
            break
        fi

    done

    if [[ $found2 == true ]]; 
    then 

    echo "LOGINNED!"

    else

    echo "TRY AGAIN !!!"

    fi 



else

echo "Nah man you not on the list "

fi 





