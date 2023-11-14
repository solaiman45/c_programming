/*
* A program that takes an ISBN number input from the user
* and breaks it down
*/


#include <stdio.h>


int main(void)
{
    int prefix, identifier, publisher, item, digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &prefix, &identifier, &publisher, &item, &digit);

    printf("GS1 prefix: %d\n", prefix);
    printf("Group identifier: %d\n", identifier);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %d\n", digit);

    return 0;
}