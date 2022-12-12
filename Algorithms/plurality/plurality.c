#include <cs50.h>
#include <stdio.h>
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
void merge(int l, int m, int r);
void mergeSort(int l, int r);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
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
            printf("Invalid vote. %i\n", i);
            i--;
        }
        // for (int i = 0; i < candidate_count; i++)
        // {
        //     printf("%s: %i\n", candidates[i].name, candidates[i].votes);
        // }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
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
    // TODO
    mergeSort(0, candidate_count - 1); 
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     printf("%s: %i\n", candidates[i].name, candidates[i].votes);
    // }
    int min = candidates[candidate_count-1].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    candidate L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i].name = candidates[l+i].name;
        L[i].votes = candidates[l+i].votes;
    }
    for (j = 0; j < n2; j++)
    {
        R[j].name = candidates[m + 1 + j].name;
        R[j].votes = candidates[m + 1 + j].votes;
    }
    i = 0;
    j = 0;
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i].votes <= R[j].votes) 
        {
            candidates[k].name = L[i].name;
            candidates[k].votes = L[i].votes;
            i++;
        }
        else 
        {
            candidates[k].name = R[j].name;
            candidates[k].votes = R[j].votes;
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        candidates[k].name = L[i].name;
        candidates[k].votes = L[i].votes;
        i++;
        k++;
    }
    while (j < n2) 
    {
        candidates[k].name = R[j].name;
        candidates[k].votes = R[j].votes;
        j++;
        k++;
    }
}

void mergeSort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, m, r);
}