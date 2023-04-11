/*
* The program asks the user to enter a U.S. dollar amount
* and then shows how to pay that amount using the smallest number
* of $20, $10, $5 and $1 bills
*/


#include <stdio.h>


#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1


int main(void)
{
    int amount, twenty, ten, five, one;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twenty = amount / TWENTY;
    amount = amount - (twenty * TWENTY);

    ten = amount / TEN;
    amount = amount - (ten * TEN);

    five = amount / FIVE;
    amount = amount - (five * FIVE);

    one = amount / ONE;
    amount = amount - (one * ONE);

    printf("$20 bills:  %d\n", twenty);
    printf("$10 bills:  %d\n", ten);
    printf("$5 bills:   %d\n", five);
    printf("$1 bills:   %d\n", one);

    return 0;
}