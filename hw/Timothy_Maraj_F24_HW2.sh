# NAME : Timothy Maraj
# CS 4350-Unix Systems Programming
# Section Number : 001
# Serial Number : 8 
# Assignment Number: 2

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

echo -n "Enter 3 integer Values - - - - > "
read int_one int_two int_three
echo $int_one $int_two $int_three



# Output what was entered

echo "1) You Entered    $int_one   $int_two   $int_three"



# Find The Smallest Number
# note that to use && or || u must [[]] double it up 
# and put a space between if and [
if [[ $int_one -lt $int_two && $int_one -lt $int_three ]]; then
    echo "2) The Smallest integer is $int_one"
elif [[ $int_two -lt $int_one && $int_two -lt $int_three ]]; then
    echo "2) The Smallest integer is $int_two"
else
    echo "2) The Smallest integer is $int_three"
fi

# Find The Larges Number
if [[ $int_one -gt $int_two && $int_one -gt $int_three ]]; then
    echo "3) The Largest integer is $int_one"
elif [[ $int_two -gt $int_one && $int_two -gt $int_three ]]; then
    echo "3) The Largest integer is $int_two"
else
    echo "3) The Largest integer is $int_three"
fi

# Find the Sum 

sum=$((int_one + int_two + int_three))
echo "4) $int_one + $int_two + $int_three = $sum"

# Find the Product
product=$(( int_one * int_two * int_three))
echo "5) $int_one * $int_two * $int_three = $product"
# Find the AVG

avg=$(( sum / 3))
echo "6) ( $int_one + $int_two + $int_three )/3 = $avg"

# Find the Square of each 
sqr_one=$((int_one * int_one))
sqr_two=$((int_two * int_two))
sqr_three=$((int_three * int_three))

echo "7) $int_one*$int_one = $sqr_one , $int_two*$int_two = $sqr_two , $int_three*$int_three = $sqr_three"
# Find the sign of each

# Fidn the even or oddness


# Find the eent numbers between 1 and the Largest number

# Find the odd numbers between 1 and the smallest numbers

# Find the Facorial of smallest number


# Determine if the second argument is a prime number 


# Calculate the distinct Sequence ? 