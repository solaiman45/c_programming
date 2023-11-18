/*
* A program that asks user for a time input in 24-hour time format,
* and displays the result in a 12-hour time format.
*/


#include <stdio.h>


int main(void)
{
    int hour, minute, hour_12_format;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (1 <= hour && hour <= 12)
    {
        switch (hour){
            case 1:
            hour_12_format = 1;
            break;
            case 2:
            hour_12_format = 2;
            break;
            case 3:
            hour_12_format = 3;
            break;
            case 4:
            hour_12_format = 4;
            break;
            case 5:
            hour_12_format = 5;
            break;
            case 6:
            hour_12_format = 6;
            break;
            case 7:
            hour_12_format = 7;
            break;
            case 8:
            hour_12_format = 8;
            break;
            case 9:
            hour_12_format = 9;
            break;
            case 10:
            hour_12_format = 10;
            break;
            case 11:
            hour_12_format = 11;
            break;
            case 12:
            hour_12_format = 12;
            break;
        }

        printf("Equivalent 12-hour time: %d:%d AM\n", hour_12_format, minute);
    } else {
        hour_12_format = hour - 12;
        printf("Equivalent 12-hour time: %d:%d PM\n", hour_12_format, minute);
    }

    return 0;
}