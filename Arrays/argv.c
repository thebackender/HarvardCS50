#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 2) 
    {
        printf("Hello, %s - %s - %s - %s - %s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);
    }
    else
    {
        printf("Hello, world");
    }
}