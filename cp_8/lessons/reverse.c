/*
* A program that asks the user to enter a series of numbers,
* then writes the numbers in reverse order
*/


#include <stdio.h>

#define ARRAY_SIZE 10


int main(void)
{
    int array[ARRAY_SIZE];

    printf("Enter %d numbers: ", ARRAY_SIZE);
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    return 0;
}