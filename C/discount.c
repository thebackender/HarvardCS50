#include <stdio.h>

float discount(float r, int p);

int main(void)
{
    float regular = 12.13;
    int percent = 35;
    float sale = discount(regular, percent);
    printf("Sale: %.2f\n", sale);
}

float discount(float r, int p) 
{
    return r * (100-p)/100;
}