/*
* The program takes date input from the user in the form of mm/dd/yyyy
* and then displays in the form yyyymmdd
*/


#include <stdio.h>


int main(void)
{
    int m,d,y;

    printf("Enter a date (mm/dd/yyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("You entered the date %d%.2d%.2d\n", y, m, d);

    return 0;
}