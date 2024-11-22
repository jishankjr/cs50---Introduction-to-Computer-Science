#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate the key
bool validate_key(string key);

int main(int argc, string argv[])
{
    // Check if the correct number of arguments are provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Store the provided key
    string key = argv[1];
    int key_len = strlen(key);

    // Check if the key has exactly 26 characters
    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Validate the key
    if (!validate_key(key))
    {
        printf("Key must only contain alphabetic characters and no duplicates.\n");
        return 1;
    }

    // Get the plaintext from the user
    string pt = get_string("plaintext: ");

    printf("ciphertext: ");

    // Substitute each character in the plaintext
    for (int i = 0, len = strlen(pt); i < len; i++)
    {
        if (isalpha(pt[i]))
        {
            // If character is lowercase, substitute with corresponding character from key
            if (islower(pt[i]))
            {
                printf("%c", tolower(key[pt[i] - 'a']));
            }
            // If character is uppercase, substitute with corresponding character from key
            else
            {
                printf("%c", toupper(key[pt[i] - 'A']));
            }
        }
        else
        {
            // Print non-alphabetical characters as is
            printf("%c", pt[i]);
        }
    }

    // Print a newline at the end
    printf("\n");

    return 0;
}

// Function to validate the key
bool validate_key(string key)
{
    // Array to track used characters
    bool used[26] = {false};

    // Check each character in the key
    for (int i = 0; i < 26; i++)
    {
        // Ensure character is alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert character to uppercase and check for duplicates
        int index = toupper(key[i]) - 'A';
        if (used[index])
        {
            return false;
        }

        // Mark character as used
        used[index] = true;
    }

    return true;
}
