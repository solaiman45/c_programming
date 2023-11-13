/*
* A program that ask asks the user to enter a U.S dollar amount,
* and then shows how to pay that amount using the smallest number of $20, 10, 5, 1
*/


#include <stdio.h>


int main(void)
{

    int twenty, ten, five, one, amount;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twenty = amount / 20;
    amount = amount - (20 * twenty);

    ten = amount / 10;
    amount = amount - (10 * ten);

    five = amount / 5;
    amount = amount - (5 * five);

    one = amount / 1;

    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf("$5 bills:  %d\n", five);
    printf("$1 bills:  %d\n", one);
    

    return 0;
}