#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n"); //asks for name
    printf("Hi, %s\n", name); //prints name
}
