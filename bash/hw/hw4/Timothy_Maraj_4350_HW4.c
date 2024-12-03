/*
NAME : Timothy Maraj
Unix Systems Programming - CS4350 - 001
Assignment Number: 4
Due Date: 10 / 16 / 2024
*/

#include <stdio.h>
#include <stdlib.h>

// Function declarations
int generateRandomNumber(); 
int generatedSum(int target_sum, int randNumOne, int randNumTwo, int count);

int main()
{  
    int exit_program = 0;  // integer value to represent True and False
                           // 0 is false
                           // 1 is true

    int randOne = 0;       // integer value to hold the value
                           // of a random number to be generated


    int randTwo = 0;       // integer value to hold the value
                           // of a random number to be generated



    int count = 0;         // integer value to hold the count of times
                           // that the sum had to be generated to match
                           // the target sum


    char user_input = '0'; // char used to hold user input
                           // 1 if we should generate numbers and target sum
                           // 9 if we should leave the program
                           // all other input is invalid 



    printf("Practicing C Programming Language\n\n");

    printf("The purpose of this program is to generate 2 random numbers ");
    printf("between 7 and 52 inclusive. A sum will be calculated by adding ");
    printf("the generated numbers. Then, the program will find the number ");
    printf(" of times it takes for the sum to be reproduced again.\n\n");


    while(!exit_program)
    {
       
        printf("Select One of the Following \n");
        printf("     1 - Generate Numbers \n");
        printf("     9 – Exit The Program     ---- >     ");
        scanf(" %c", &user_input); 
        getchar();  
        printf("\n"); 

        switch(user_input)
        {
            case '1': 
            
            randOne = generateRandomNumber(); 
            randTwo = generateRandomNumber(); 
            printf("First Generated Number : %d\n", randOne); 
            printf("Second Generated Number : %d\n", randTwo); 
            printf("\n"); 

            int temp_sum = randOne + randTwo; 
            printf("First Number + Second Number =     %d\n\n", temp_sum);
            printf("Processing . . . . . . .\n\n\n");

            
            count = 0;
            
            randOne = generateRandomNumber(); 
            randTwo = generateRandomNumber();
            while (randOne + randTwo != temp_sum) {
                count = generatedSum(temp_sum, randOne, randTwo, count);
                randOne = generateRandomNumber(); 
                randTwo = generateRandomNumber();
            }

            
            count = generatedSum(temp_sum, randOne, randTwo, count);

            // Cannot adjust lines below to meet 
            // similar space requirments of the 
            // rubric without goign over the 80 char limit 
            printf("\n");
            printf("Number of Times the Numbers were Generated\n");
            printf("Before the Desired sum was reached   =  %d\n\n\n", count);
            break;

            case '9': 
                // Exit the program
                exit_program = 1; 
                printf("\n");
                printf("Program is Terminated\n\n");
                printf("Implemented By Timothy Maraj\n\n");
                printf("10 - 16 - 2024\n");
                break; 

            default: 
                // Invalid input
                printf("** Invalid Selection **\n\n\n");
                break; 
        }
    }

    return 0; 
}


int generateRandomNumber()
{
    return rand() % 46 + 7; 
}


int generatedSum(int target_sum, int randNumOne, int randNumTwo, int count)
{   
    int newsum = randNumOne + randNumTwo; 

    printf("Generating First Number    =      %d\n", randNumOne);
    printf("Generating Second Number   =      %d\n", randNumTwo);
    printf("The sum of the generated numbers is  : %d\n\n\n", newsum);

    return count + 1; 
}
