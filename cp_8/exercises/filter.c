/*
* A program that reads a message by the user and translates it into B1FF-speak,
* then prints it out with 10 exclamation marks. 
*/


#include <stdio.h>
#include <ctype.h>


int main(void)
{   
    char characters[100] = {0};
    char ch;
    int counter = 0;
    printf("Enter message: ");

    ch = getchar();
    while (ch != '\n') {
        characters[counter] = ch;
        counter++;
        ch = getchar();
    }

    // Turning all characters to uppercase.
    for (int i = 0; i < 100; i++) {
        if (characters[i] != 0) {
            
            characters[i] = toupper(characters[i]);
        }
    }

    printf("In B1FF-speak: ");
    // Converst certain letters to numeric versions.
    for (int i = 0; i < 100; i++) {
        if (characters[i] != 0 ) {
            if (characters[i] == 'A') {
            characters[i] = '4';
            }
            else if (characters[i] == 'B') {
                characters[i] == '8';
            }
            else if (characters[i] == 'E') {
                characters[i] = '3';
            }
            else if (characters[i] == 'I') {
                characters[i] = '1';
            }
            else if (characters[i] == 'O') {
                characters[i] = '0';
            }
            else if (characters[i] == 'S') {
                characters[i] = '5';
            }

            printf("%c", characters[i]);
        }
    }

    for (int i = 10; i > 0; i--) {
        printf("!");
    }

    printf("\n");
    return 0;
}