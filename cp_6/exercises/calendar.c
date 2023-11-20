/*
* A program that prints a one-month calendar.
*/



#include <stdio.h>


int main(void)
{
    int month, day;

    printf("Enter number of days in month: ");
    scanf("%d", &month);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &day);

    for (int i = 1; i < day; i++)
    {
        printf("    ");
    }

    for (int i = 1; i <= month; i++)
    {
        printf("%3d ", i);
        day++;

        if (day == 8) {
            day = 1;
            printf("\n");
        }
    }
    return 0;
}