// Problem Set 1 - CS50 Week 1 Tasks

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Task 1: Hello, World
void hello_world()
{
    printf("Hello, World!\n");
}

// Task 2: Mario (Less Comfortable) - Pyramid
void mario_easy()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// Task 3: Cash - Minimum coins needed for change
void cash()
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    int cents = round(dollars * 100);
    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    
    for (int i = 0; i < 4; i++)
    {
        coins += cents / denominations[i];
        cents %= denominations[i];
    }
    
    printf("%i\n", coins);
}

// Task 4: Credit Card Validator
bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;
    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return sum % 10 == 0;
}

void credit()
{
    long number = get_long("Number: ");
    if (check_luhn(number))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main()
{
    hello_world();
    mario_easy();
    cash();
    credit();
    return 0;
}
