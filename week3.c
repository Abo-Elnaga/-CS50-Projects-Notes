// Problem Set 3 - CS50 Week 3 Tasks

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Task 1: Sorting Algorithm
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Task 2: Plurality Voting System
#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX_CANDIDATES];
int candidate_count;

void vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return;
        }
    }
}

void print_winner()
{
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main()
{
    // Example usage
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    candidate_count = 3;
    candidates[0] = (candidate) {"Alice", 0};
    candidates[1] = (candidate) {"Bob", 0};
    candidates[2] = (candidate) {"Charlie", 0};
    
    vote("Alice");
    vote("Bob");
    vote("Alice");
    print_winner();
    
    return 0;
}
