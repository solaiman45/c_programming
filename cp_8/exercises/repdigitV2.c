/*
* A Program that prompts user to enter a number of digits,
* Shows which digits (if any) were repeated.
*/


#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    int digit_seen[10] = {false};
    int digit_rep[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        
        digit = n % 10;

        if (digit_seen[digit]) {
            digit_rep[digit] = true;
        }

        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeaded digit(s): ");
    for (int i = 0; i < 10; i++) {
        if (digit_seen[i] == true && digit_rep[i] == true) {
            printf(" %d ", i);
        }
    }
    printf("\n");
    return 0;
}