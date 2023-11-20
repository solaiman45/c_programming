/*
* A program that prompts user for input and prints out a table of squares with a for statement.
*/



#include <stdio.h>


int main(void)
{
    int i, n;

    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        printf("%d\t%d\n", i, i*i);
    }

    return 0;
}