#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int key;
    if (argc == 2)
    {
        int n = strlen(argv[1]);
        for (int i = 0 ; i < n ; i++)
        {
            if (isdigit(argv[1][i]) < 1)
            {
                // checking for non digit value
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        key = atoi(argv[1]);        // convert string key to integer

        if (key <= 0)
        {
            // checking for zero or negative values
            printf("Usage: ./caesar key\n");
            return 1;
        }

        string p = get_string("plaintext: ");   // get the message from user

        /*
            Now it's time to play with all characters only

        */

        printf("ciphertext: ");
        for (int i = 0, pl = strlen(p) ; i < pl ; i++)
        {
            if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z'))
            {
                if (islower(p[i]))
                {
                    printf("%c", (((p[i] - 97) + key) % 26) + 97);  // change the index of lower alphas
                }
                else
                {
                    printf("%c", (((p[i] - 65) + key) % 26) + 65);  // change the index of upper alphas
                }
            }
            else
            {
                printf("%c", p[i]);
            }

        }
        printf("\n");


    }

    else
    {
        printf("Usage: ./caesar key\n");    // return 1 if recieved less or greater than 1 argument
        return 1;
    }
}

