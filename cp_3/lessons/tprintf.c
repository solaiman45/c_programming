/*
* Prints int and float values in various formats
*/

#include <stdio.h>

int main(void)
{
    int x;
    float y;


    x = 40;
    y = 839.21f;

    printf("|%d|%5d|%-5d|%5.3d|\n", x, x, x, x);
    printf("|%10.3f|%10.3e|%-10g|\n", y, y, y);

    return 0;
}