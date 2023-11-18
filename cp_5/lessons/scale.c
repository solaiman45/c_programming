/*
* A program that takes user input of wind speed in knots,
* and displays the correcpsonding decription.
*/


#include <stdio.h>


int main(void)
{
    int wind_speed;

    printf("Enter win speed (in knots): ");
    scanf("%d", &wind_speed);

    if (wind_speed < 1)
    {
        printf("Calm\n");
    } else if (wind_speed <= 3)
    {
        printf("Light air\n");
    } else if (wind_speed <= 27)
    {
        printf("Breeze\n");
    } else if (wind_speed <= 47)
    {
        printf("Gale\n");
    } else if (wind_speed <= 63)
    {
        printf("Storm\n");
    } else {
        printf("Hurricane");
    }

    return 0;
}