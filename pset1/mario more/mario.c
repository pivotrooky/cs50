#include <cs50.h>
#include <stdio.h>

void print_pyramid(int input);
void print_pyramid_line(int input, int line);
void print_character_loop(int counter, char character);
void print_character_loop_reverse(int counter, char character);

int main(void)
{
    int input; //initialize variables

    do
    {
        input = get_int("How high will your pyramid be? Type a number between 1 and 8!\n"); //get height
        print_pyramid(input);
        //calls big loop

    }

    while (!(input > 0 && input < 9)); //checks correct height input
}

void print_pyramid(int input)
{

    int line;

    for (line = 1; line <= input; line++) //line loop
    {
        print_pyramid_line(input, line);
        //this prints a whole line of blanks and hashes
    }
}

void print_pyramid_line(int input, int line)
{

    print_character_loop_reverse(input - line, ' ');
    //prints batch of blanks
    print_character_loop(line, '#');
    //prints first batch of hashes
    printf("  ");
    //prints spaces to separate batches
    print_character_loop(line, '#');
    //prints second batch of hashes
    printf("\n");

}

void print_character_loop(int counter, char character)
{
    for (int length = 0; length < counter; length++)
    {
        printf("%c", character);
    }
    return;
}

void print_character_loop_reverse(int counter, char character)
{
    //TODO: make a single function which decides which of these two to call,
    //and figure out how to do it without needing 3 params
    for (int length = counter; length >= 1; length--)
    {
        printf("%c", character);
    }
    return;
}

