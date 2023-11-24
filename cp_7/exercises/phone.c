/*
* A program that translates an alphabetic phone number into numeric form.
*/


#include <stdio.h>



int main(void)
{
    char num, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9;

    printf("Enter a phone number: ");

    num = getchar();
    while( num != '\n') {
        if (num == 'A' || num == 'B' || num == 'C') {
            printf("%d", two);
        }
        else if (num == 'D' || num == 'E' || num == 'F')
        {
            printf("%d", three);
        }
        else if (num == 'G' || num == 'H' || num == 'I')
        {
            printf("%d", four);
        }
        else if (num == 'J' || num == 'K' || num == 'L')
        {
            printf("%d", five);
        }
        else if (num == 'M' || num == 'N' || num == 'O')
        {
            printf("%d", six);
        }
        else if (num == 'P' || num == 'R' || num == 'S')
        {
            printf("%d", seven);
        }
        else if (num == 'T' || num == 'U' || num == 'V')
        {
            printf("%d", eight);
        }
        else if (num == 'X' || num == 'Y' || num == 'Z')
        {
            printf("%d", nine);
        }
        else {
            printf("%c", num);
        }

        num = getchar();
        
    }

    return 0;
}