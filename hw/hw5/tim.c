/*
NAME : Timothy Maraj
Unix Systems Programming - CS4350 - 001
Assignment Number: 5
Due Date: 10 / 28 / 2024
*/
#include <stdio.h>



// function prototypes 
int int_sqrt(int); 
int is_prime(int); 
int is_perfect_sqare(int); 
void print_primes(int); 
void print_square_pairs(int); 



int main() {
    int number = 0;
    char choice;

    
    do
    {
            printf("Enter A Positive Integer ---- > : ");
            scanf("%d", &number);
            if(number >= 5001 || number < 0)
            {
                printf("\n");
                printf("Invalid Number, Number "); 
                printf("must be between 1 and 5000\n\n\n");
            }
            else
            {
                printf("\n"); 

                // Check if the entered number is prime
                if (is_prime(number)) {
                    printf("%d is a Prime Number\n\n", number);
                } else {
                    printf("%d is Not Prime\n\n", number);
                }

                // Print all primes up to the entered number
                print_primes(number);

                // Print all square pair numbers up to the entered number
                print_square_pairs(number);

                // Ask if the user wants to repeat the process
                
                printf("\n");  
            }
        
             do {
                printf("Would you like to repeat the process ");
                printf("for another number?\n\n");
                printf("Enter Y or y, N or n ----> ");
                scanf(" %c", &choice);
                if(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n') 
                {
                    printf("Invalid choice, must enter Y, y, N, or n\n\n");

                }
            }while(choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n');
    }while(choice == 'Y' || choice == 'y');




    return 0;
}


// Function to estimate square root using Newton's method
// so I wouldnt have to include the math lib
// not aviable on zeuz linux server 
int int_sqrt(int num) {
    if (num <= 1) return num;
    int a = num, b = num / 2 + 1;
    while (b < a) {
        a = b;
        b = (a + num / a) / 2;
    }
    return a;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= int_sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to print all prime numbers up to the given limit
void print_primes(int limit) {
    printf("All Prime Numbers between 2 and %d are:\n\n", limit);
    int first = 1;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf(".\n\n");
}

// Function to check if a number is a perfect square
int is_perfect_square(int num) {
    int sqrt_num = int_sqrt(num);
    return (sqrt_num * sqrt_num == num);
}

// Function to find and print all square pair numbers
void print_square_pairs(int limit) {
    printf("The square pair numbers are:-\n\n");
    printf("N        P        N + P    P - N\n");
    printf("--------------------------------\n");
    for (int i = 1; i < limit; i++) {
        for (int j = i + 1; j <= limit; j++) {
            if (is_perfect_square(i + j) && is_perfect_square(j - i)) {
                printf("%-6d   %-6d   %-6d   %-6d\n", i, j, i + j, j - i);
            }
        }
    }
    printf("\n\n");
}
