/*
* A program that computes the volume of a sphere 
* with the radius inputted by the user
*/


#include <stdio.h>


#define FRACTION (4.0f / 3.0f)
#define PI 3.1415

int main(void)
{
    float volume, radius;

    printf("Enter radius of shpere: ");
    scanf("%f", &radius);

    radius = radius * radius * radius;

    volume = FRACTION * PI * radius;

    printf("Volume of a Sphere with 10-m radius: %.2f", volume);

    return 0;
}