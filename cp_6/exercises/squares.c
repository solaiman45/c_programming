/*
* A program that takes user input (int n) and prints all even squares between 1 and n.
*/



#include <stdio.h>


int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 2; i * i <= num; i += 2)
    {
        printf("%d\n", i * i);
    }

    return 0;
}