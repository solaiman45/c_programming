/*
* A program that computes the volume of a sphere with a 10-m radius
*/



#include <stdio.h>


#define FRACTION (4.0f / 3.0f)
#define PI 3.1415
#define RADIUS_CUBED (10 * 10 * 10)

int main(void)
{
    float volume;

    volume = FRACTION * PI * RADIUS_CUBED;

    printf("Volume of a Sphere with 10-m radius: %.2f", volume);

    return 0;
}