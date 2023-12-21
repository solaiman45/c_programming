/*
* A Program that prints a table showing how many times each digit appears in the number.
*/



#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    int digit_seen[10] = {false};
    int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int digit_counter[10] = {0};

    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        digit_seen[digit] = true;

        if (digit_seen[digit]) {
            digit_counter[digit] += 1;
        };

        n /= 10;
    }

    printf("Digit:\t\t");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", values[i]);
    }

    printf("\n");
    printf("Occurrences:    ");
    for (int i = 0; i < 10; i++) {
        printf(" %d ", digit_counter[i]);
    }

    printf("\n");
    return 0;
}