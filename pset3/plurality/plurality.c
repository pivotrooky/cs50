#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int validate_usage(int argc);
int get_max_votes(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    validate_usage(argc);

    // Populate array of candidates
    candidate_count = argc - 1;

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //gets max_votes value
    int max_votes = get_max_votes();

    //prints all candidates who got as many votes
    for (int j = 0; j < MAX - 1; j++)
    {
        if (candidates[j].votes == max_votes)
        {
            printf("%s\n", candidates[j].name);

        }
    }
    return;
}


int validate_usage(int argc)
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        exit(1);
    }
    if (argc - 1 > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        exit(2);
    }
    return 0;
}

int get_max_votes(void)
{
    int max_votes = candidates[0].votes;

    for (int i = 1; i < MAX - 1; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    return max_votes;
}