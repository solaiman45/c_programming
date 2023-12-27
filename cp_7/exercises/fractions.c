/*
* This program is a modification of addfrac.c from chapter 3. We prompt the user for two fractions,
* and allow them to choose to add, subtract, multiply or divide the fractions.
*/



#include <stdio.h>



int main(void)
{

    int num1, denom1, num2, denom2;
    char ch, operator;

    int result_num, result_denom;

    printf("Enter first fratction (2/5): ");
    scanf("%d/%d", &num1, &denom1);

    getchar();

    printf("Enter operator: (+, -, *, /): ");
    while ((ch = getchar()) != '\n') {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operator = ch;
            break;
        } else {
            printf("Enter operator: (+, -, *, /): ");
            ch = getchar();
        }
    }

    printf("Enter first fratction (2/5): ");
    scanf("%d/%d", &num2, &denom2);


    
    if (operator == '+') {
        result_num = num1 * denom2 + num2 * denom1;
        result_denom = denom1 * denom2;

        printf("The addition is: %d/%d", result_num, result_denom);
    } else if (operator == '-') {
        result_num = num1 * denom2 - num2 * denom1;
        result_denom = denom1 * denom2;

        printf("The subtraction is: %d/%d", result_num, result_denom);
    } else if (operator == '*') {
        result_num = num1 * num2;
        result_denom = denom1 * denom2;

        printf("The multiplication is: %d/%d", result_num, result_denom);
    } else {
        result_num = num1 * denom2;
        result_denom = denom1 * num2;
        printf("The division is: %d/%d", result_num, result_denom);
    }
    printf("\n");

    


    return 0;
}