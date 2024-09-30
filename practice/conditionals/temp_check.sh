#!/bin/bash

read -p " what is the temp rn? " temp

if [[ $temp -ge 90 ]]; 
then 
echo too hot! 
exit; 
fi

echo "nice, not too hot shesh.."