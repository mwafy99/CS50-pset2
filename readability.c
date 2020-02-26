/*
    Readability - Created By Mwafy
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main(void)
{
    string text = get_string("Text: ");     // get text from user
    int n = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;      // count the number of lettters
        }

        if (text[i] == ' ')
        {
            words++;    // count the number of words based on spaces
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;    // count the number of sentences based on three factors (.,!,?)
        }
    }

    float l = (100 * (float)letters) / (float)words;

    float s = (100 * (float)sentences) / (float)words;

    float grade = round(0.0588 * l - 0.296 * s - 15.8);
    int x = (int) grade;
    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }

}
