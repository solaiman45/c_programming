/*
* A program that asks the user to enter a dollars-and-cents amount,
* then displays the amount with 5% tax added
*/


#include <stdio.h>


#define TAX (1.05f)


int main(void)
{
    float amount, after_tax;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    after_tax = amount * TAX;

    printf("With tax added: %.2f", after_tax);

    return 0;
}
