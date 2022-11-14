#include <stdio.h>

int main (void)
{
    int n;
    do
    {
        scanf("%i", &n);
        
    }
    while (n < 1);
    for (int i = 0; i < n; i++) {
        printf("%c\n", '?');
    }
}