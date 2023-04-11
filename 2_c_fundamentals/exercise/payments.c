/*
* The program prompts to enter
*   - amount of load
*   - interest rate
*   - monthly payment
* and then calculates the remaining balance after 1st, 2nd and 3rd monthly payments
*/


#include <stdio.h>


#define MONTHS 12

int main(void)
{
    float loan, rate, payment;

    printf("Enter amount of load: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &rate);
    
    rate = 1 + ((rate / 100) / MONTHS);

    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    loan = (loan - payment) * rate;
    printf("Balance remaining after first payment:   $%.2f\n", loan);

     loan = (loan - payment) * rate;
     printf("Balance remaining after second payment:  $%.2f\n", loan);

     loan = (loan - payment) * rate;
     printf("Balance remaining after third payment:   $%.2f\n", loan);

     return 0;
}