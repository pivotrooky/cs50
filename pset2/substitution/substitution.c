#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(string k, string plaintext); //declare cipher function
string alpha = "abcdefghijklmnopqrstuvwxyz";
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(int argc, string argv[])
{


    string k = argv[1];
    int count[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //array of counters

    if (argc != 2)
    {
        printf("Usage: ./substitution key (letters)\n");
        exit(1); //exit program if wrong number of arguments
    }

    if (strlen(k) != 26)
    {
        printf("Usage: ./substitution key (all 26 letters)\n");
        exit(1); //exit program if not 26 chars
    }

    for (int i = 0; i < strlen(k); i++) //loop to check all chars of key
    {
        for (int j = 0; j < 26; j++) //check every char for containing letters
        {


            if (k[i] == alpha[j] || k[i] == ALPHA[j])
            {
                count[j]++; //add to each counter
                break;
            }
        }
    }


    for (int j = 0; j < 26; j++)
    {
        if (count[j] != 1)
        {
            printf("Usage: ./substitution key (all 26 letters only once!)\n");
            exit(1); //exit program if some letter twice or not found
        }
    }


    printf("k = %s\n", k); //print key
    string plaintext = get_string("plaintext: "); //get input
    string ciphertext = cipher(k, plaintext); //store ciphertext
    printf("ciphertext: %s\n", ciphertext); //print output
}

string cipher(string k, string plaintext) //define cipher function
{

    string ciphertext = plaintext; //starting point

    for (int i = 0; i < strlen(plaintext); i++) //loop for each character
    {
        for (int j = 0; j < 26; j++) //loop to check for letter
        {
            if (plaintext[i] == tolower(alpha[j])) //check if char is found in lowercase alphabet
            {
                ciphertext[i]  = tolower(k[j]); //change char to lowercase
                break;
            }

            else if (plaintext[i] == toupper(alpha[j])) //check if char is found in lowercase alphabet
            {
                ciphertext[i]  = toupper(k[j]); //change char to lowercase
                break;
            }
        }
    }

    return ciphertext; //return
}

