/*
* A program that counts the number of vowels in a sentence.
*/


#include <stdio.h>
#include <ctype.h>


int main(void)
{
    int counter = 0;
    char ch;

    printf("Enter a sentence: ");

    ch = getchar();

    while(ch != '\n') {
        ch = toupper(ch);

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            counter++;
        }

        ch = getchar();
    }

    if (counter == 1) {
        printf("Your sentence contains %d vowel.\n", counter);
    } else {
        printf("Your sentence contains %d vowels.\n", counter);
    }
    

    return 0;
}