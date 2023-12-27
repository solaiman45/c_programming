/*
* A program that calculates the average word length for a sentence.
* puntuation marks are part of the sentence.
*/


#include <stdio.h>


int main(void)
{
    float length = 0.0f;
    float num_words = 1.0f;
    float average = 0.0f;

    char ch;

    printf("Enter a sentence: ");
    while (ch = getchar()) {
        if (ch == '\n') {
            break;
        } else if (ch != ' ') {
            length++;
        }

        if (ch == ' ') {
            num_words++;
        }
    }

    printf("Average: %.1f\n", length/num_words);

    return 0;
}