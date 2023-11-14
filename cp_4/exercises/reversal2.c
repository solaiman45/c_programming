/*
* This is an extension of reversal.c in that reversal2.c takes in 3 digits
*/


#include <stdio.h>


#define FACTOR_100 100
#define FACTPR_10 10

int main(void)
{

    int first, middle, last, num, second_part;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    first = num / FACTOR_100;
    second_part = num % FACTOR_100;
    middle = second_part / FACTPR_10;
    last = second_part % FACTPR_10;

    printf("The reversal is %d%d%d\n", last, middle, first);

    return 0;
}