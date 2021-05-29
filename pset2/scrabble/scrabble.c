#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

string get_winning_message(int score1, int score2);
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    string message = get_winning_message(score1, score2);

    printf("%s", message);
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
            //this means no points are added
        }

        int char_index;
        //this variable will be equal to the corresponding index of the array TOTAL

        if (isupper(word[i]))
        {
            char_index = word[i] - 'A';
        }

        else
        {
            char_index = word[i] - 'a';
        }

        score += POINTS[char_index];
    }

    return score;
}

string get_winning_message(int score1, int score2)
{
    if (score1 > score2)
    {
        return "Player 1 wins!";
    }

    if (score2 > score1)
    {
        return "Player 2 wins!";
    }

    return "Tie!";
}