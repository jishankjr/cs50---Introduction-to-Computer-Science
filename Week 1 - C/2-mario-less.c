#include <stdio.h>

int main(void)
{
    int rows, i, j, spaces;

    while (1)
    {
        printf("Enter number of rows (greater than 0): ");
        scanf("%d", &rows);

        if (rows > 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a number greater than 0.\n");
        }
    }

    for (i = 1; i <= rows; i++)
    {
        // Print spaces
        for (spaces = 1; spaces <= rows - i; spaces++)
        {
            printf(" ");
        }

        // Print '#' symbols
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
