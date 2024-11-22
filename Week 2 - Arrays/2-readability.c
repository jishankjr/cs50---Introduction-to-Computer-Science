#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int countWords(string text);
int countSentences(string text);
int countLetters(string text);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Count the number of words in the text
    int w_n = countWords(text);

    // Count the number of sentences in the text
    int s_n = countSentences(text);

    // Count the number of letters in the text
    int l_n = countLetters(text);

    // Calculate L: the average number of letters per 100 words
    float L = ((float) l_n / w_n) * 100;

    // Calculate S: the average number of sentences per 100 words
    float S = ((float) s_n / w_n) * 100;

    // Calculate the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print the grade level based on the index
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

// Function to count the number of words in the text
int countWords(string text)
{
    int wordCount = 0;
    bool inWord = false;

    // Loop through each character in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the current character is a space, newline, or tab
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            inWord = false;
        }
        else if (!inWord)
        {
            // If we are not already in a word, start a new word
            inWord = true;
            wordCount++;
        }
    }
    return wordCount;
}

// Function to count the number of sentences in the text
int countSentences(string text)
{
    int count = 0;
    int len = strlen(text);

    // Loop through each character in the text
    for (int i = 0; i < len; i++)
    {
        // Check if the current character is a sentence-ending punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Function to count the number of letters in the text
int countLetters(string text)
{
    int count = 0;

    // Loop through each character in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the current character is an alphabetic letter
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            count++;
        }
    }
    return count;
}
