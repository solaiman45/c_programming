/*
* A program that prompts user for input and prints out a table of squares.
*/



#include <stdio.h>


int main(void)
{
    int i, n;

    printf("Enter the number of entries in a table: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n)
    {
        printf("%d\t%d\n", i, i * i);
        i++;
    }

    return 0;
}