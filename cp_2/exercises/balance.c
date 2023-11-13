/*
* A program that calculates the remaining balance on a loan,
* after the first, second and third monthly payments
*/


#include <stdio.h>


#define ANNUAL 12
#define PERCENTAGE_CONVERTOR 100

int main(void)
{
    float amount, interest_annual, interest_monthly, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);

    printf("Enter interest rate: ");
    scanf("%f", &interest_annual);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    interest_annual = interest_annual / PERCENTAGE_CONVERTOR;
    interest_monthly = interest_annual / ANNUAL;

    amount = amount - monthly_payment;
    amount = amount * (1 + interest_monthly);

    printf("Balance remaining after first payment: %.2f\n", amount);

    
    amount = amount - monthly_payment;
    amount = amount * (1 + interest_monthly);

    printf("Balance remaining after second payment: %.2f\n", amount);

    
    amount = amount - monthly_payment;
    amount = amount * (1 + interest_monthly);

    printf("Balance remaining after third payment: %.2f\n", amount);

}