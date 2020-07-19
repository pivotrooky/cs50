#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(int k, string plaintext); //declare cipher function

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1); //exit program if wrong number of arguments
    }

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (isdigit(argv[1][j]) == 0)
        {
            printf("Usage: ./caesar key\n");
            exit(1); //exit program if wrong type of argument
        }
    }

    string k = argv[1];
    printf("k = %s\n", k); //print key
    string plaintext = get_string("plaintext: "); //get input
    string ciphertext = cipher(atoi(k), plaintext); //store ciphertext
    printf("ciphertext: %s\n", ciphertext); //print output
}

string cipher(int k, string plaintext) //define cipher function
{
    string ciphertext = plaintext; //starting point

    for (int i = 0; i < strlen(plaintext); i++) //loop for each character
    {
        if (isalpha(plaintext[i]) != 0) //if non-alpha leave unchanged
        {
            if (isupper(plaintext[i]) != 0)
            {
                ciphertext[i] = (((plaintext[i] + k) - 65) % 26) + 65;
            }
            else
            {
                ciphertext[i] = (((plaintext[i] + k) - 97) % 26) + 97;
            }
        }
    }
    return ciphertext; //return
}