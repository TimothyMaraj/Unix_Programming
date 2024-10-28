/*
NAME : Timothy Maraj
CS4350 - Unix Systems Programming     Section Number: 001
Assignment Number: 5
Due Date: 10 / 28 / 2024
*/
#include <stdio.h>

// function prototypes 
int sqroot(int); 
int isPrime(int); 
int is_perfect_sqare(int); 
void printPrimes(int); 
void printSquarePairs(int); 

int main() {
    int number = 0; // integer value for number choosen by user
                    // any number from 1 to 5000 is valid
                    // negtaive numbers less than 0 are invalid 
                    // numbers outside the 2 to 5000 inclusive are invalid
                    // numbers inside this range are valid


    char choice;    // for the user input to cotinue the program
                    // if the user selects y or Y then the program continues
                    // if the user selectes n or N then program terminates
                    // all other inputs are invalid 



    printf("Mathematics and Computer Programming\n");

    printf("The program will determine whether or not the integer that was");
    printf(" entered from the keyboard is prime. Also, the program will find");
    printf("all prime numbers between 2 and the integer that is entered.\n");
    

    printf("Prime number is a number that is divisible by itself");
    printf(" and one only such as 2, 3, 5, 7, 11, 13 ...\n\n");


    printf("Square numbers are certain pairs of numbers when added together");
    printf("give a square number and when subtracted ");
    printf("also give a square number.\n\n\n");



    do
    {
        printf("Enter A Positive Integer ---- > : ");
        scanf("%d", &number);
        if(number >= 5001 || number < 1)
        {
            if( number < 0)
            {
                printf("\n"); 
                printf("Invalid Number, Number must be positive.\n\n\n");
            }
            else
            {
                printf("\n");
                printf("Invalid Number, Number "); 
                printf("must be between 1 and 5000\n\n\n");
            }
        }
        else
        {
            printf("\n"); 

            if (isPrime(number)) 
            {
                printf("%d is a Prime Number\n\n", number);
            }
            else 
            {
                printf("%d is Not Prime\n\n", number);
            }

            printPrimes(number);
            printSquarePairs(number);
            printf("\n");  
        }

        do 
        {
            printf("Would you like to repeat the process ");
            printf("for another number?\n\n");
            printf("Enter Y or y, N or n ----> ");
            scanf(" %c", &choice);
            printf("\n");
            if(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n') 
            {
                
                printf("Invalid choice, must enter Y, y, N, or n\n\n");
                printf("\n");
            }
        }while(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n');
    }while(choice == 'Y' || choice == 'y');


    printf("Mathematics and Computer Programming\n");
    printf("Prepared by Timothy Maraj\n");
    printf("10 - 28- 2024\n");

    return 0;
}


// Newton's method for calculating squaretroot
// so I wouldnt have to include the math lib
// not aviable on zeuz linux server 
int sqroot(int num) {
    if (num <= 1) return num;
    int a = num, b = num / 2 + 1;
    while (b < a) {
        a = b;
        b = (a + num / a) / 2;
    }
    return a;
}

// checks if a number is prime
int isPrime(int num) 
{
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqroot(num); i += 2)
    {
        if (num % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}

// prints all primes
void printPrimes(int limit) 
{
    printf("All Prime Numbers between 2 and %d are:\n\n", limit);
    int first = 1;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i)) 
        {
            if (!first) 
            {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf(".\n\n");
}


int isPerfectSquare(int num) 
{
    int sqrt_num = sqroot(num);
    return (sqrt_num * sqrt_num == num);
}

//print all square pair numbers
void printSquarePairs(int limit) 
{
    printf("The square pair numbers are:-\n\n");
    printf("N        P        N + P    P - N\n");
    printf("--------------------------------\n");
    for (int i = 1; i < limit; i++)
    {
        for (int j = i + 1; j <= limit; j++) 
        {
            if (isPerfectSquare(i + j) && isPerfectSquare(j - i)) 
            {
                printf("%-6d   %-6d   %-6d   %-6d\n", i, j, i + j, j - i);
            }
        }
    }
    printf("\n\n");
}
