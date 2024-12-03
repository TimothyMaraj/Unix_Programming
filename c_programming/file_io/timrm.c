#include <stdio.h> 

// argc is the number of commands
// argv is the commands themselves
int main(int argc,  char *argv[])
{

    if(argc<=1)
    {
        printf("no commandline arguments given \n");
        return 1;
    }

    // else
    // get file name from command line args
    // check file name exist in the path
    // delete
    // note here argv[0] is the 
    // and always is name of the file 
    printf("You want to delete %s ? y/n? \n",argv[1]);
    char userinput='a'; 
    scanf("%s",&userinput);
    if(userinput == 'y' || userinput == 'n')
    {
        if(userinput == 'y')
        {
            int status = -1; 
            status = remove(argv[1]);
            if(status)
                printf("Something Went Wrong...Try again\n");
            else
                printf("Deleted %s",argv[1]);

        }
        else    
            printf("Don't wast the effort, next time...\n");    
    }
}