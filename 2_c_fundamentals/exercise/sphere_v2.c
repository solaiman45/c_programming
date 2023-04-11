/*
* The program computes the volume of a sphere with with the user entering the size of the radius
* using the formula v=4/3*pi*r^3
*/


#include <stdio.h>


#define FRACTION (4.0f / 3.0f)
#define PI (3.1415)


int main(void)
{
    float radius, volume;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

    volume = FRACTION * PI * (radius * radius * radius);

    printf("Volume of the sphere: %.2f\n", volume);
    return 0;
}