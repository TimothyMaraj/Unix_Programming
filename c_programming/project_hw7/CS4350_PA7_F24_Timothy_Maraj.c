/*
NAME : Timothy Maraj
Unix Systems Programming - CS4350 - 001
Assignment Number: 7
Due Date: 12 / 02 / 2024
*/

/*******************************
 

This program, project 7 explores the use of threads to due certain tasks
Those include 
    - searching 
    - deleteing 
    - inserting
into a global array where a hash function is used to find the 
index in which a certain book is located... this hash function is 
implemented using book[0] % 10 ... this line takes the first char and mods 
it by 10 giving us number between 0-9. After as such an incrementer is
used to up the hash by 1 to get through the full length of the array

These threads are also synced using a global mutex and joined to ensure 
they exist properly 


NOTE: Sometimes, a signal will be missed by the waiting thread 
      this is a limitation of the lib pthreads and not the code
      this can happen more frequently if one runs the program 
      repeatedly 


********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ARRAY_SIZE 16  // const for Array Size to be used when 
                        // creating the array of books 

#define MAX_NAME_LEN 20 // const for max number of char in each book title

#define INIT_ARRAY_ELEMENTS 14 // const for number of 
                                //  initial array elements 

#define MAX_NUMBER_THREADS 11

char books[ARRAY_SIZE][MAX_NAME_LEN]; // Global array for the book names

int linearProbeSearch = 0; // Counter for search probes
int linearProbeDelete = 0; // Counter for delete probes
int linearProbeInsert = 0; // Counter for inserting probe

// insert is different from search? yes
// explicit difference in the project 
// "Thread ... Search ..." vs "Thread ... Insert"

pthread_mutex_t lock; // Mutex lock
pthread_cond_t cond_vars[MAX_NUMBER_THREADS]; // cond vars


int step = 0; 
int numberOfBooks = 0; // keep track of books in array

char emptyBook[2];

// List of book names
const char* bookNames[] = 
{
    "March", "The-Road", "So-Big", "Beloved", "The-Goldfinch",
    "Julius-Caesar", "The-Overstory", "The-Da-Vinci-Code",
    "Animal-Farm", "Verity", "Educated", "The-Hobbit", "Sybil", "Nostromo"
};

void initEmptyBook()
{
    emptyBook[0]='*';
    emptyBook[1]='\0';
}

// Initialize the book array
void initArray() 
{
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        strcpy(books[i],emptyBook); // Null-terminate each string
                                       // Null termiantor needed to prevent
                                       // Missing Null terminator error
                                       // with Char Array Element
    }

}


int hashFunction(const char* book) 
{
    return book[0] % 10;
}

void insertBook(const char* book) 
{
    int hash = hashFunction(book);
    int original_hash = hash;
    int probe_count = 0;

    

    while(strcmp(books[hash], emptyBook) != 0) 
    {
        hash = (hash + 1) % ARRAY_SIZE;
        probe_count++;

        if(hash == original_hash) 
        {
            printf("Table is Full\n");
            
            return;
        }
    }

    strcpy(books[hash], book);
    linearProbeInsert += probe_count;


}





void* populateBooks(void* arg) 
{
    
    pthread_mutex_lock(&lock);
   
    pthread_cond_wait(&cond_vars[0], &lock);
    for(int i = 0; i < INIT_ARRAY_ELEMENTS; i++) 
    {
        insertBook(bookNames[i]);
        numberOfBooks++;
    }
    
    step = 2;
    pthread_cond_signal(&cond_vars[1]);
    pthread_mutex_unlock(&lock);
    return NULL;
}


// Display the array
void* displayBooksAndIntro(void* arg) 
{
    pthread_mutex_lock(&lock);
   
    

        pthread_cond_wait(&cond_vars[1], &lock);

    printf("\n\n");
    printf("Welcome to my Hashing Program \n\n");
    printf("------------------------------ \n\n");
    printf("A. Creates a string array of size 16. Assigning - to each\n");
    printf("   location in the array indicating that the array is empty.\n");
    printf("B. Populates 14 elements of the array with book names.\n");
    printf("C. If a collision occurs, linear probing will find the next\n"); 
    printf("   available position / location.\n");
    printf("D. The generated array will be displayed in 6 lines.\n");
    printf("   Each line contains 3 book names separated by 3 tabs.\n\n");

    printf("The Generated Array.\n");
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%-30s", books[i]); // Left-align each string with a fixed 
                                   // width of 30 to simiulate
                                   // 3 tabs and leave room for the 
                                   // name of the book 
        if((i + 1) % 3 == 0) printf("\n"); 
    }
    printf("\n\n");
    
    step = 3;
    pthread_cond_signal(&cond_vars[2]);
    pthread_mutex_unlock(&lock);
    return NULL;

}

void* searchAnimalFarm(void* arg) 
{
    const char* book = "Animal-Farm";
    int hash = hashFunction(book);
    int original_hash = hash;

    pthread_mutex_lock(&lock);
    
    
    pthread_cond_wait(&cond_vars[2], &lock);

    while(strcmp(books[hash], book) != 0) 
    {
        
        linearProbeSearch++;
        hash = (hash + 1) % ARRAY_SIZE;
        if(hash == original_hash) break;
    }

    printf("Searching For a Book Name ( %s ) in the Table.\n", book);
    if(strcmp(books[hash], book) == 0) 
    {
        printf("The book name %s was found in location %d.\n\n", book, hash);
    } 
    
    step = 4;
    pthread_cond_signal(&cond_vars[3]);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* searchEmma(void* arg)
{
    const char* book = "Emma";
    int hash = hashFunction(book);
    int original_hash = hash;

    pthread_mutex_lock(&lock);
    
    pthread_cond_wait(&cond_vars[3], &lock);

   
    while(strcmp(books[hash], book) == 1 && numberOfBooks < ARRAY_SIZE-1) 
    {
        linearProbeSearch++; 
        hash = (hash + 1) % ARRAY_SIZE;
        if(hash == original_hash) 
            break;
    }

    printf("Searching For a Book Name ( %s ) in the Table.\n", book);
    if(strcmp(books[hash], book) == 0) 
    {
        printf("The book name %s was found in location %d.\n\n", book, hash);
    }
    else
        printf("The book name Emma was not found in Table.\n\n");

    step = 5;
    pthread_cond_signal(&cond_vars[4]);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* insertHamlet(void* arg) 
{
    const char* book = "Hamlet";
    int hash = hashFunction(book);
    int original_hash = hash;

    pthread_mutex_lock(&lock);
    
    
    pthread_cond_wait(&cond_vars[4], &lock);

    
    while(strcmp(books[hash], emptyBook) != 0) 
    {
        hash = (hash + 1) % ARRAY_SIZE;
        linearProbeInsert++;
    }

    strcpy(books[hash], book);
    printf("Insert a New Book Name ( %s ) in the Table.\n", book);
    printf("Book Name ( %s ) is inserted in location %d.\n\n", book, hash);
    numberOfBooks++; 

    step = 6;
    pthread_cond_signal(&cond_vars[5]);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* insertPassage(void* arg) 
{
    const char* book = "A-Passage-To-India";
    int hash = hashFunction(book);
    int original_hash = hash;

    pthread_mutex_lock(&lock);
    
    pthread_cond_wait(&cond_vars[5], &lock);

    while(strcmp(books[hash], emptyBook) != 0) 
    {
        hash = (hash + 1) % ARRAY_SIZE;
        linearProbeInsert++; 
    }

    strcpy(books[hash], book);
    printf("Insert a New Book Name ( %s ) in the Table.\n", book);
    printf("Book Name ( %s ) is inserted in location %d.\n\n", book, hash);
    numberOfBooks++;
    step = 7;
    pthread_cond_signal(&cond_vars[6]);
    pthread_mutex_unlock(&lock);
    return NULL;
}
void* displayBooks(void* arg)
{
    // arg should be the message 
    // in the first case it should default to 
    //"The Generated Array:\n"

    char* message = (char*) arg; 
    
    pthread_mutex_lock(&lock);
    
        pthread_cond_wait(&cond_vars[6], &lock);
    printf("%s\n",message);
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%-30s", books[i]); // Left-align each string with a fixed 
                                   // width of 30 to simiulate
                                   // 3 tabs and leave room for the 
                                   // name of the book 
        if((i + 1) % 3 == 0) printf("\n"); 
    }
    printf("\n\n");
    step = 8;
    pthread_cond_signal(&cond_vars[7]);
    pthread_mutex_unlock(&lock);
    return NULL;
}


void* insertRelativity(void* arg) 
{
    const char* book = "Relativity";
    int hash = hashFunction("Relativity");
    int original_hash = hash;
    int probe_count = 0;
    
    pthread_mutex_lock(&lock);
   
  
    pthread_cond_wait(&cond_vars[7], &lock);
    printf("Insert a New Book name ( %s ) in the Table.\n","Relativity");
    // not indexing
    // actuall number of books 
    if(numberOfBooks == ARRAY_SIZE)
    {
        printf("Table is Full\n\n");
        
        step = 9;
        pthread_cond_signal(&cond_vars[8]);
        pthread_mutex_unlock(&lock);
        return NULL;
    }
}


// update for linearProbeDelete

void* deleteEmma(void* arg) 
{
    
    int hash = hashFunction("Emma");
    int original_hash = hash;

   

    pthread_mutex_lock(&lock);
    

    
    pthread_cond_wait(&cond_vars[8], &lock);

    printf("Delete a Book Name ( %s ) from the Table. \n","Emma");
    while(strcmp(books[hash], "Emma") != 0) 
    {
        linearProbeDelete++;
        hash = (hash + 1) % ARRAY_SIZE;
        if(hash == original_hash) break;
    }

    if(strcmp(books[hash], "Emma") == 0) 
    {
        printf("Book Name ( %s ) is deleted.\n\n", "Emma");
        strcpy(books[hash],emptyBook);
        numberOfBooks--; 
    } 
    else
    {
        printf("Book Name ( %s ) was not found in the Table.\n\n", "Emma");
    }

    
    step = 10;
    pthread_cond_signal(&cond_vars[9]);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* deleteVerity(void* arg) 
{
    char* book = "Verity";
    int hash = hashFunction(book);
    int original_hash = hash;

    
    pthread_mutex_lock(&lock);
    
  
        pthread_cond_wait(&cond_vars[9], &lock);

    printf("Delete a Book Name ( %s ) from the Table. \n","Verity");
    while(strcmp(books[hash], "Verity") != 0) 
    {

        linearProbeDelete++;
        hash = (hash + 1) % ARRAY_SIZE;
        if(hash == original_hash) break;
    }

    if(strcmp(books[hash], "Verity") == 0) 
    {
        printf("Book Name ( %s ) is deleted.\n\n",book);
        strcpy(books[hash], emptyBook);
        numberOfBooks--;
    } 
    
    step = 11;
    pthread_cond_signal(&cond_vars[10]);
    pthread_mutex_unlock(&lock);
    
    return NULL;
}


void* displayBooksEnd(void* arg)
{
    // arg should be the message 
    // in the first case it should default to 
    //"The Generated Array:\n"

    char* message = (char*) arg; 
    
    pthread_mutex_lock(&lock);
    
    pthread_cond_wait(&cond_vars[10], &lock);
    printf("%s\n",message);
    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("%-30s", books[i]); // Left-align each string with a fixed 
                                   // width of 30 to simiulate
                                   // 3 tabs and leave room for the 
                                   // name of the book 
        if((i + 1) % 3 == 0) printf("\n"); 
    }
    printf("\n\n");
    
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() 
{

    // init empty book array const 
    // is not the book array its self
    // used for comparison 
    initEmptyBook();

    char* message = "The Generated Array."; // init message
                                            // for array output 

    pthread_t threads[MAX_NUMBER_THREADS]; // array of threads
                                           // to be created

    pthread_mutex_init(&lock, NULL);      // init the mutex
                                          // to be used

    for (int i = 0; i < MAX_NUMBER_THREADS; i++) 
    {
        pthread_cond_init(&cond_vars[i], NULL);
    }

    initArray(); // gives the array null values 
                // seperate from what thread 1 does 
                // which is give the array book names 

    
    pthread_create(&threads[0], NULL, populateBooks, NULL);
    

    pthread_create(&threads[1], NULL, displayBooksAndIntro, NULL);
   

    pthread_create(&threads[2], NULL, searchAnimalFarm, NULL);
    
    pthread_create(&threads[3], NULL, searchEmma, NULL);
    

    pthread_create(&threads[4], NULL, insertHamlet, NULL);
    

    pthread_create(&threads[5], NULL, insertPassage, NULL);
   

    // update message to "The Table After the 2 books were inserted:"
    message = "The Table After the 2 books were inserted:";
    pthread_create(&threads[6], NULL, displayBooks, (void*)message);
    


    pthread_create(&threads[7], NULL, insertRelativity, NULL);
  


    pthread_create(&threads[8], NULL, deleteEmma, NULL);
   


    pthread_create(&threads[9], NULL, deleteVerity, NULL);
 

    // update message to "The Table After 1 book was deleted:"
    message = "The Table After 1 book was deleted:";
    pthread_create(&threads[10], NULL, displayBooksEnd, (void*)message);
   

    pthread_mutex_lock(&lock);
    step=1;
    pthread_cond_signal(&cond_vars[0]); 
    pthread_mutex_unlock(&lock);

    for(int i = 0; i < MAX_NUMBER_THREADS;i++)
        pthread_join(threads[i],NULL);

    printf("The number of linear probes when each ");
    printf("number is hashed, and collision\n");
    printf("ccurred when searching for a ");
    printf("book in the array is %d \n\n",linearProbeSearch);

    printf("The number of linear probes when each ");
    printf("number is hashed, and collision\n");
    printf("ccurred when deleting for a ");
    printf("book in the array is %d \n\n",linearProbeDelete);
    pthread_mutex_destroy(&lock); // nesesary to destroy mutex before program
                                  // termination 
    for (int i = 0; i < MAX_NUMBER_THREADS; i++) {
        pthread_cond_destroy(&cond_vars[i]);
    }
    printf("This hashing program was implemented by\n");
    printf("Timothy Maraj - 12 - 2 - 2024\n\n");

    return 0;
}
