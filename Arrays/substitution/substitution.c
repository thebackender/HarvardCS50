#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if (argc == 2) {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        string key = argv[1];
        string s = get_string("plaintext: ");
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] > 64 && s[i] < 91)
            {
                s[i] = key[s[i]-65];
            }
            if (s[i] > 96 && s[i] < 123)
            {
                s[i] = key[s[i]-97]+32;
            }
            i++;
        }
        printf("ciphertext: %s\n", s);
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
    }
}