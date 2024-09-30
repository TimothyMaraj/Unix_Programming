#!/bin/bash 


admin="six"


read -p "Enter Username:" uname

if [[ $uname == $admin ]]; 
then

echo welcome commander


else

echo not recognize ... exiting
 

fi