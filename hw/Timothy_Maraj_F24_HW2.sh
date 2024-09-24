# NAME : Timothy Maraj
# CS 4350-Unix Systems Programming
# Section Number : 001
# Serial Number : 8 
# Assignment Number: 2
# Due Date 9 / 23 / 2024 no later than 5:15 pm.


#!/bin/sh


echo "
This Script is Designed and Implemented by Timothy Maraj

The function of This script is to :

1. Display the integer arguments that are entered.
2. Display the smallest of the integer arguments
3. Display the largest of the integer arguments
4. Sum of the 3 integer arguments .
5. Product of the 3 integer arguments.
6. Average of the 3 integer arguments.
7. Square of each integer argument.
8. Determine that each integer argument is positive, negative or
zero.
9. Determine that each integer argument is odd, or even
10. Find all even numbers between 1 and the first integer
argument.
11. Find all odd numbers between 1 and the third integer
argument.
12. Find the factorial of the last integer argument.
13. Determine whether or not the second integer argument is a
prime number.
14. Calculating Distinct Sequence of the second integer
"


int_one="ERR"
int_two=-"ERR"
int_three="ERR"

printf "Enter 3 integer Values - - - - > "
read int_one int_two int_three
echo $int_one $int_two $int_three



# 1. Display the integer arguments that are entered.
echo "1) You Entered    $int_one   $int_two   $int_three"



#2. Display the smallest of the integer arguments
if [[ $int_one -lt $int_two && $int_one -lt $int_three ]]; then
    echo "2) The Smallest integer is $int_one"
    smallest=$int_one
elif [[ $int_two -lt $int_one && $int_two -lt $int_three ]]; then
    echo "2) The Smallest integer is $int_two"
    smallest=$int_two
else
    echo "2) The Smallest integer is $int_three"
    smallest=$int_three
fi

# 3. Display the largest of the integer arguments
if [[ $int_one -gt $int_two && $int_one -gt $int_three ]]; then
    echo "3) The Largest integer is $int_one"
    largest=$int_one
elif [[ $int_two -gt $int_one && $int_two -gt $int_three ]]; then
    echo "3) The Largest integer is $int_two"
    largest=$int_two
else
    echo "3) The Largest integer is $int_three"
    largest=$int_three
fi



# 4. Sum of the 3 integer arguments .

sum=$((int_one + int_two + int_three))
echo "4) $int_one + $int_two + $int_three = $sum"

# 5. Product of the 3 integer arguments.
product=$(( int_one * int_two * int_three))
echo "5) $int_one * $int_two * $int_three = $product"
# 6. Average of the 3 integer arguments.

avg=$(( sum / 3))
echo "6) ( $int_one + $int_two + $int_three )/3 = $avg"

# 7. Square of each integer argument.
sqr_one=$((int_one * int_one))
sqr_two=$((int_two * int_two))
sqr_three=$((int_three * int_three))

echo "7) $int_one*$int_one = $sqr_one , $int_two*$int_two = $sqr_two , $int_three*$int_three = $sqr_three"

# 8. Determine that each integer argument is positive, negative or zero.
if [[ $int_one -gt 0 ]]; then
    printf "8) $int_one is positive ,"
    
else 
    if [[ $int_one -eq 0 ]]; then
        printf "8) $int_one is zero ,"
    fi 
    printf "8) $int_one is negative ,"
fi



if [[ $int_two -gt 0 ]]; then
    printf " $int_two is postive ,"
     
else
    if [[ $int_two -eq 0 ]]; then
        printf " $int_two is zero ,"
    fi
    printf " $int_two is negative , "
fi



if [[ $int_three -gt 0 ]]; then
    printf " $int_three is postive \n"
else
    if [[ $int_three -eq 0 ]]; then
    printf " $int_three is zero \n"
    fi
    printf " $int_three is negative \n"
fi




# 9. Determine that each integer argument is odd, or even


if [ $(expr $int_one % 2) -eq 0 ]; then
    printf "9) $int_one is even ,"
else 
    printf "9) $int_one is odd ,"
fi

if [ $(expr $int_two % 2) -eq 0 ]; then
    printf " $int_two is even ,"
else
    printf " $int_two is odd ,"
fi

if [ $(expr $int_three % 2) -eq 0 ]; then
    printf " $int_three is even \n"
else
    printf " $int_three is odd \n"
fi



# 10. Find all even numbers between 1 and the first integer argument.

if [ $int_one -gt 0 ]; then
    
    counter=0
    printf "10) All even numbers between 1 and $int_one are : "
    until [ $counter -eq $int_one ]; do
        if [ $(expr $counter % 2) -eq 0 ]; then
            printf " $counter "
        fi
        let counter+=1
    done

else 

    counter=$int_one
        printf "10) All even numbers between $int_one and 1 are : "
        until [ $counter -eq 1 ]; do
            if [ $(expr $counter % 2) -eq 0 ]; then
                printf " $counter "
            fi
            let counter+=1
        done

fi 
printf "\n"
# 11. Find all odd numbers between 1 and the third integer argument.

if [ $int_three -gt 0 ]; then
    counter=1 
    printf "11) All odd numbers between 1 and $int_three are : "
    until [ $counter -gt $int_three ]; do
        if [ $(expr $counter % 2) -eq 1 ]; then
            printf " $counter "
        fi
        let counter+=1  
    done
else 

    counter=$int_three
        printf "11) All odd numbers between 1 and $int_three are : "
        until [ $counter -eq 1 ]; do
            if [ $(expr $counter \* -1 % 2) -eq 1 ]; then
                printf " $counter "
            fi
            let counter+=1
        done

fi 
printf "\n"


# 12. Find the factorial of the last integer argument.

if [ $int_three -lt 0 ]; then 
    echo "12) Error, third argument is a negative number. Cannot take the factorial of numbers less than 0"
fi

# We can assume that the number is > 0 but I added a check in here
# for practice

if [ $int_three -eq 1 -o  $int_three -eq 0 ]; then
    echo "12) Factorial of $int_three is 1" 
else

    counter=1
    factorial=1
    until [ $counter -gt $int_three ]; do 
        factorial=$(expr $counter \* $factorial)
        let counter+=1
    done 
fi 
echo "12) Factorial $int_three is $int_three $factorial "

#13. Determine whether or not the second integer argument is a prime number.



# 14. Calculating Distinct Sequence of the second integer

printf "14) Calculating Distinct Sequence "
while [ $int_two -ne 1 ]; do
    if (( int_two % 2 == 0 )); then
        int_two=$(( int_two / 2 )) 
    else
        int_two=$(( 3 * int_two + 1 ))  
    fi
    printf "%d " $int_two
done
printf "\n" 


echo "End of script"
echo "Timothy Maraj - 9 - 23 - 2024"



