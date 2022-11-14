// clang file.c -o file -lcs50
#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    string s = get_string("Text: ");
    int i = 0, w = 0, c = 0, l = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            w++;
        }
        if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
        {
            l++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            c++;
        }
        i++;
    }
    w++;
    float L = l*100.0/w, S = c*100.0/w;
    float x = (0.0588 * L - 0.296 * S - 15.8);
    int index;
    if (x > 4.5)
    {
        index = (int)x + 1;
    }
    else
    {
        index = (int)x;
    }
    printf("Grade: %i\n", index);
    printf("Letters: %i\nWords: %i\nSentences: %i\n", l, w, c);
    // printf("Grade: %i\n", index);
    return 0;
}