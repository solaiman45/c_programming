/*
* A progrma that finds the smallest and largest integer of four integers entered by the user
*/


#include <stdio.h>


int main(void)
{
    int one, two, three, four, smallest, largest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &one, &two, &three, &four);

    if (one > two && one > three && one > four)
    {
        largest = one;
    } else if (two > three && two > four)
    {
        largest = two;
    } else if (three > four)
    {
        largest = three;
    } else {
        largest = four;
    }


    if (one < two && one < three && one < four)
    {
        smallest = one;
    } else if (two < three && two < four)
    {
        smallest = two;
    } else if (three < four)
    {
        smallest = three;
    } else {
        smallest = four;
    }

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}