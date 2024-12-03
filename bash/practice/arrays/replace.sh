#!/bin/bash


arr=( "1" "2" "3" "4" )
echo $arr
arr2=("${arr[@]:1}")
echo ${arr2[@]}