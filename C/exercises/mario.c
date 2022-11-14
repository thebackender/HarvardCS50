#include <stdio.h>

void print_repeat(char c, int t);

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        scanf("%i", &n);
    } while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++) 
    {
        print_repeat(' ', n - i);
        print_repeat('#', i);
        print_repeat(' ', 2);
        print_repeat('#', i);
        print_repeat(' ', n - i);
        printf("\n");
    }
}

void print_repeat(char c, int t)
{
    while (t--)
        printf("%c", c);
}