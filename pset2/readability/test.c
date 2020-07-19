#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>


int calc_grade (string text);
int calc_letters (string text);
int calc_words (string text);
int calc_sentences (string text);

int letters, words, sentences, grade, lphw, sphw;

int main(void)

{
    string text = get_string("Text:\n");
    letters = calc_letters(text);
    words = calc_words(text);
    sentences = calc_sentences(text);
    lphw = 100 * letters / words;
    sphw = 100 * sentences / words;
    grade = calc_grade(text);

    printf("Text: %s\n", text);
    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);
    printf("Grade: %d\n", grade);
    printf("char 0: %c\n", text[0]);
    printf("int 0: %d\n", text[0]);
    printf("LPHW: %d\n", lphw);
    printf("SPHW: %d\n", sphw);

}

int calc_grade (string text)

{
    grade = 0;
    lphw = 100 * letters / words;
    sphw = 100 * sentences / words;
    grade = 0.0588 * lphw - 0.296 * sphw - 15.8;
    //12,5832 - 2,072 - 15,8
    return grade;
}

int calc_letters (string text)

{
    letters = 214;
    return letters;
}


int calc_words (string text)

{
    words = 56;
    return words;
}

int calc_sentences (string text)

{
    sentences = 4;
    return sentences;
}