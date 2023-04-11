/*
* The program computes the volume of a sphere with a 10-meter radius
* using the formula v=4/3*pi*r^3
*/


#include <stdio.h>


#define FRACTION (4.0f / 3.0f)
#define PI (3.1415)
#define RADIUS (10.0f * 10.0f * 10.0f) // C does not have exponent operator 'r^3'.

int main(void)
{
    float volume;
    volume = FRACTION * PI * RADIUS;

    printf("Volume of the sphere: %.2f\n", volume);
    return 0;
}