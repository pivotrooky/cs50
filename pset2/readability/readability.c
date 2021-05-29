#include <string.h>
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

float calc_letters(string text); // declare functions
float calc_words(string text);
float calc_sentences(string text);
float calc_grade(string text);

float calc, letters, words, sentences, grade; //declare variables

int main(void)

{
    string text = get_string("Text:\n"); //get user input
    letters = calc_letters(text);
    words = calc_words(text);
    sentences = calc_sentences(text);
    grade = calc_grade(text);

    if (grade < 1) //check if grade falls between standard parameters
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.0f\n", round(grade));
    }
}
//define functions
float calc_grade(string text)

{
    float letters_per_hundred_words = 100 * letters / words; //get stats
    float sentences_per_hundred_words = 100 * sentences / words;
    grade = 0.0588 * letters_per_hundred_words - 0.296 * sentences_per_hundred_words - 15.8; //formula
    return grade;
}

float calc_letters(string text)

{
    letters = 0; //initialize variable

    for (int i = 0, n = strlen(text); i < n; i++) //loop to check each character individually
    {
        if (isalpha(text[i]) != 0) //check if is alphanumeric
        {
            letters++;
        }
    }
    return letters;
}


float calc_words(string text)

{
    words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]) != 0)
        {
            if (isblank(text[i - 1]) == 0)
            {
                words++;
            }
        }
    }
    return words;
}

float calc_sentences(string text)

{
    sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}