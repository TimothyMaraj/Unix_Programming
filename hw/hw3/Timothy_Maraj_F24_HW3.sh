# NAME : Timothy Maraj
# CS 4350-Unix Systems Programming
# Section Number : 001
# Serial Number : 8 
# Assignment Number: 3
# Due Date 10 / 4 / 2024 no later than 12:00 pm.

#!/bin/bash

function opener()
{
    echo 
    echo Shell Programming by Timothy Maraj 
    echo
}

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
    grep [[:digit:]] zNew.txt
    echo
}

function showLowercase()
{
    echo "5. All lines with lowercase characters : "
    grep [[:lower:]] zNew.txt
    echo
}


function showUppercase()
{
    echo "6. All lines with uppercase characters : "
    grep [[:upper:]] zNew.txt
    echo
}

function showAlphanum()
{
    echo "7. All lines with alphanumeric characters : "
    grep [[:alnum:]] zNew.txt
    echo
}

function showPunct()
{
    echo "8. All lines with punctuation characters : "
    grep [[:punct:]] zNew.txt
    echo
}

function showS_space()
{
    echo "9. All the lines with the letter s followed by space : "
    grep s[[:space:]] zNew.txt
    echo
}


function showZeus_space()
{
    echo "10. All the lines with the word zeus followed by space :"
    grep 'zeus'[[:space:]] zNew.txt
    echo
}

function show_programming()
{
    echo "11. All the line that the word programming appears at the end of the line : "
    grep 'programming$' zNew.txt
    echo 
}

function show_fall()
{
    echo "12. All the lines that the word Fall appears at the beginning of the sentence :"
    grep '^Fall' zNew.txt
    echo
}

function show_startwith_C_end_with_0()
{
    echo "13. All lines that have a word that starts with C and ends with 0:"
    grep 'C[a-zA-Z0-9]*0' zNew.txt
    echo
}


function show_startwith_s_end_with_l()
{
    echo "14. All lines that contain a word that starts with s and ends with l:"
    grep 's[a-zA-Z]*l' zNew.txt
    echo

}


function remove_zNewtext()
{
    echo "15. Deleting the existing File zNew.txt"
    rm zNew.txt
    echo
}

function display_zNewtext()
{
    echo "16. Display the content of zNew.txt :"

    if [ -e zNew.txt ];
    then
        cat zNew.txt
    fi
    echo
    echo
}

function footer() 
{
    echo Prepared by Timothy Maraj 
    echo
    echo 10-4-2024 
    echo
}


opener

createFile
showAllContents
showAlpha
showDigits
showLowercase
showUppercase
showAlphanum
showPunct
showS_space
showZeus_space
show_programming
show_fall
show_startwith_C_end_with_0
show_startwith_s_end_with_l
remove_zNewtext
display_zNewtext

footer