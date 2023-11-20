/*
* A program that prompts user to enter numbers one by one,
* and displays the largest nonneative number.
*/


#include <stdio.h>


int main(void)
{
    
    float largest = 0.0f, num;
    
    do
    {
        printf("Enter numbers (0 to exit): ");
        scanf("%f", &num);

        if (num > largest) {
            largest = num;
        }
    } while (num != 0);   

    printf("The largest number entered was: %.2f", largest);

    return 0;

}