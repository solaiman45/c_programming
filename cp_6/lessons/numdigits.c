/*
* A program that calculates the number of digits in an integer entered by the user.
*/



#include <stdio.h>


int main(void)
{
    int digts = 0, n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    do {
        n /= 10;
        digts++;
    } while( n > 0);

    printf("The number has %d digits\n", digts);
    
    return 0;
}