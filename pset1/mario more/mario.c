#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input, line, blank, hash; //initialize variables 

    do
    
    {
        input = get_int("How high will your pyramid be? Type a number between 1 and 8!\n"); //get height
        
        for (line = 1; line <= input; line++) //line loop
        {
            for (blank = input - line; blank >= 1; blank--) //blank loop
            {
                printf(" ");
            }

            for (hash = 1; hash <= line; hash++) //hash loop
            {
                printf("#");
            }

            printf("  ");

            for (hash = 1; hash <= line; hash++) //hash loop
            {  
                printf("#");
            }

            printf("\n");
        }

    }
           
    while (!(input > 0 && input < 9)); //checks correct height input
}
