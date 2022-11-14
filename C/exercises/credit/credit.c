// #include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int get_length(long num);
bool checksum(long num);

int main(void) 
{
    long n;
    scanf("%li", &n);
    int l = get_length(n);
    if (!checksum(n))
        printf("INVALID123\n");
    else 
    {
        if (l == 16)
        {
            long first = n/1000/1000/1000/1000/100;
            long second = n/1000/1000/1000/1000/1000;
            if (first == 51 || first == 52 || first == 53 || first == 54 || first == 55)
            {
                printf("MasterCard\n");
            }
            else if (second == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        } 
        else if (l == 15)
        {
            long first = n/1000/1000/1000/1000/10;
            if (first == 34 || first == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        } 
        else if (l == 13)
        {
            long second = n/1000/1000/1000/1000;
            if (second == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        } 
        else
        {
            printf("INVALID\n");
        }
    }
}

int get_length(long x)
{
    int len = 0;
    while (x/10)
    {
        x = x/10;
        len++;
    }
    return len+1;
}

bool checksum(long num)
{
    int a = 0, b = 0, add;
    while (num)
    {
        add = ((num%100)/10)*2;
        a += add/10 + add%10;
        b += num%10;
        num /= 100;
    }
    return !((a+b)%10);
}