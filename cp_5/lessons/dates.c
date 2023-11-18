/*
* A program that prompts the user to enter two dates and indicates which one comes ealier in the calendar.
*/


#include <stdio.h>


int main(void)
{
    int first_day, first_month, first_year, second_day, second_month, second_year;
    int first_position = 2, second_position = 1;

    printf("Enter first date (dd/mm/yy): ");
    scanf("%d/%d/%d", &first_day, &first_month, &first_year);

    printf("Enter second date (dd/mm/yy): ");
    scanf("%d/%d/%d", &second_day, &second_month, &second_year);

    if (first_year < second_year)
    {
        first_position = 1;
        second_position = 2;
    }
    else if (first_year == second_year)
    {
        if (first_month < second_month)
        {
            first_position = 1;
            second_position =2;
        }
        else if (first_month == second_month)
        {
            if (first_day < second_day)
            {
                first_position = 1;
                second_position = 2;
            }
        }
    }

    if (first_position == 1)
    {
        printf("%.2d/%.2d/%.2d is earlier than ", first_day, first_month, first_year);
        printf("%.2d/%.2d/%.2d", second_day, second_month, second_year);
    } else {
        printf("%.2d/%.2d/%.2d is earlier than ", second_day, second_month, second_year);
        printf("%.2d/%.2d/%.2d", first_day, first_month, first_year);
    }

    return 0;
}