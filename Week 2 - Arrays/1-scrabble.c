#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int s_score(string word);

// Introducing external variable to store points value
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{

    // Input word for player 1
    string word1 = get_string("Player 1: ");

    // Input word for player 2
    string word2 = get_string("Player 2: ");

    // Returned value is stored here
    int s1 = s_score(word1);
    int s2 = s_score(word2);

    // Comparing using if loop
    if (s1 > s2)
    {
        printf("Player 1 wins\n");
    }
    else if (s2 > s1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

int s_score(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {

        // Convert each character to uppercase
        char upper_char = toupper(word[i]);

        // Check if the character is a letter
        if (isalpha(upper_char))
        {
            score += POINTS[upper_char - 'A'];
        }
    }

    return score;
}
