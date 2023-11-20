/*
* A program that asks the user to enter a fraction,
* then reduces the fraction to lowest terms.
*/


#include <stdio.h>


int main(void)
{
    int m, n, numerator, denominator, temp, GCD;

    printf("Enter two integers: (6/12): ");
    scanf("%d/%d", &m, &n);

    numerator = m;
    denominator = n;

    while(n != 0) {
        temp = n;
        n = m % n;
        m = temp;

        GCD = m;
    }

    numerator = numerator / GCD;
    denominator = denominator / GCD;

    printf("In lowest terms: %d/%d\n", numerator, denominator);

    return 0;
}