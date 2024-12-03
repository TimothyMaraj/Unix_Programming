#!/bin/sh
var="hello"

echo $var
echo "$var"
echo '$var'
echo \$var


echo "Enter in some text"
read var

echo "'$var' now equals $var"