# NAME : Timothy Maraj
# CS 4350-Unix Systems Programming
# Section Number : 001
# Serial Number : 8 
# Assignment Number: 3
# Due Date 10 / 4 / 2024 no later than 12:00 pm.

#!/bin/bash
function createFile()
{
    echo "1. Creating a new File zNew.txt."
    touch zNew.txt
    echo Fall 2024 > zNew.txt
    echo CS4350 >> zNew.txt
    echo Section  >> zNew.txt
    echo 001 >> zNew.txt
    echo scripts and shell programming using >> zNew.txt
    echo zeus ide >> zNew.txt
    echo @ TEXAS STATE UNIVERSITY >> zNew.txt
    echo
}


function showAllContents()
{   
    echo "2. The content of the created file is : "
    cat zNew.txt; 
    echo 
}

function showAlpha()
{
    echo "3. All lines with alphabet characters : "
    grep [[:alpha:]] zNew.txt
    echo
}

function showDigits()
{
    echo "4. All lines with digits : "
    grep [[:digits:]] zNew.txt
    echo
}

function showLowercase()
{
    echo "5. All lines with lowercase characters : "
    grep [[:lower:]] zNew.txt
    echo
}

function footer() 
{
    echo "Prepared by Timothy Maraj \n 10-4-2024 "
}



createFile
showAllContents
showAlpha
showLowercase


footer