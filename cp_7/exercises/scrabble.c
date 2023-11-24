/*
* A program that imitates a scrabble game.
*/


#include <stdio.h>
#include <ctype.h>


int main(void)
{
    int total_score = 0, one = 1, two = 2, three = 3, four = 4, five = 5, eight = 8, ten = 10;
    char ch;

    printf("Enter a word: ");

    ch = getchar();

    while (ch != '\n')
    {
        ch = toupper(ch);

        if (ch == 'Q' || ch == 'Z') {
            total_score += ten;
        }
        else if (ch == 'J' || ch == 'X')
        {
            total_score += eight;
        }
        else if (ch == 'K')
        {
            total_score += five;
        }
        else if (ch == 'F' || ch == 'H' || ch == 'V' || ch == 'W' || ch == 'Y')
        {
            total_score += four;
        }
        else if (ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P')
        {
            total_score += three;
        }
        else if(ch == 'D' || ch == 'G')
        {
            total_score += two;
        }
        else {
            total_score += one;
        }

        ch = getchar();
    }

    printf("Scrabble value: %d\n", total_score);
    return 0;
}