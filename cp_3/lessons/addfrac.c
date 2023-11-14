/*
* A program that takes fractions as user inputs and adds them together,
* example; 5/6 + 3/4
*/


#include <stdio.h>


int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter two fractions separated by a plus sign (5/6+3/4): ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("The sum is %d/%d", result_num, result_denom);

    return 0;
}