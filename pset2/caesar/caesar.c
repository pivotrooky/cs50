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

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            exit(1); //exit program if wrong type of argument
        }
    }

    string key = argv[1];
    printf("k = %s\n", key); //print key
    string plaintext = get_string("plaintext: "); //get input
    string ciphertext = cipher(atoi(key), plaintext); //store ciphertext
    printf("ciphertext: %s\n", ciphertext); //print output
}

string cipher(int k, string plaintext) //define cipher function
{
    string ciphertext = plaintext; //starting point

    for (int i = 0, n = strlen(plaintext); i < n; i++) //loop for each character
    {
        if (isalpha(plaintext[i]) == 0) //if non-alpha leave unchanged
        {
            continue;
        }

        if (isupper(plaintext[i]) != 0)
        {
            ciphertext[i] = (((plaintext[i] + k) - 'A') % 26) + 'A';
        }
        else
        {
            ciphertext[i] = (((plaintext[i] + k) - 'a') % 26) + 'a';
        }
    }
    return ciphertext;
}