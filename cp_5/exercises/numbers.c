/*
* A program that counts how many digits a number has
*/


#include <stdio.h>



int main(void)
{
    int number, digits;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (0 <= number && number <= 9)
    {
        digits = 1;
    }
    else if (10 <= number && number <= 99)
    {
        digits = 2;
    } else {
        digits = 3;
    }

    printf("The number %d has %d digits\n", number, digits);

    return 0;
}