/*
* A program that takes a digit as user input and reverses its order,
* 28 into 82
*/


#include <stdio.h>


int main(void)
{
    int num, first, second;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    first = num / 10;
    second = num % 10;

    printf("The reversal is: %d%d\n", second, first);

    return 0;
}