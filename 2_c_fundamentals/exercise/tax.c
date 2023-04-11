/*
* The program prompts the user to enter a dollar-and-cents amount
* and then displays the amount with a 5% tax added
*/


#include <stdio.h>


#define TAX_ADD (1.05f);

int main(void)
{
    float amount, with_tax;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    with_tax = amount * TAX_ADD;
    printf("With tax added: %.2f\n", with_tax);

    return 0;
}