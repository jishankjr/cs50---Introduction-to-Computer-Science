#include <stdio.h>
int main(void)
{
    // Declaring all required variables
    int i, a, b, c, d, cash, count = 0;

    // Assiging the value of coins as a,b,c,d for required calculations
    a = 25;
    b = 10;
    c = 5;
    d = 1;

    // Ensuring the input is number rather than other character and alphabet
    while (1)
    {
        // Asking the change to the user
        printf("Change owed: ");
        scanf("%d", &cash);

        if (cash < 0)
        {
            break; // Break if cas is non-negative
        }
        else
        {
            printf("Change owed: ");
            scanf("%d", &cash);
        }
    }

    // Calculating number of coins for 25 cents coin
    while (cash >= 25)
    {
        cash = cash - a;
        count++;
    }

    if (cash > 0)
    {
        // Calculating number of coins for 10 cents coin
        while (cash >= 10)
        {
            cash = cash - b;
            count++;
        }

        if (cash > 0)
        {
            // Calculating number of coins for 5 cents coin
            while (cash >= 5)
            {
                cash = cash - c;
                count++;
            }

            if (cash > 0)
            {
                // Calculating number of coins for 1 cent coin
                while (cash >= 1)
                {
                    cash = cash - d;
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}
