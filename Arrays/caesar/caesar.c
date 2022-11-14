#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    // int key = argv[1][0] - 48;
    // printf("%i\n", key*2);
    if (argc == 2 && atoi(argv[1]))
    {
        int key = atoi(argv[1]);
        string s = get_string("plaintext: ");
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] > 64 && s[i] < 91)
            {
                s[i] = (((s[i] - 64) + key)%26) + 64;
            }
            if (s[i] > 96 && s[i] < 123)
            {
                s[i] = (((s[i] - 96) + key)%26) + 96;
            }
            i++;
        }
        printf("Cichertext: %s\n", s);
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
    }
    
}