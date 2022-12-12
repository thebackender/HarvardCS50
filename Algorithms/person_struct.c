#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;


int main(void)
{
    person people[2];
    people[0].name = "David";
    people[0].number = "123";
    people[1].name = "Alex";
    people[1].number = "987";
    for (int i = 0; i < 2; i++)
    {
        printf("Name: %s, Number: %s\n", people[i].name, people[i].number);
    }
    
}