/*
* An improved version of the phone.c program which translates an alphabetic phone number into numeric form
*/


#include <stdio.h>


int main(void)
{
    char ch;
    
    printf("Enter phone number: ");
    while ((ch = getchar()) != '\n') {
        if (65 <= ch && ch <= 67) {
            printf("2");
        } else if (68 <= ch && ch <= 70) {
            printf("3");
        } else if (71 <= ch && ch <= 73) {
            printf("4");
        } else if (74 <= ch && ch <= 76) {
            printf("5");
        } else if (77 <= ch && ch <= 79) {
            printf("6");
        } else if (80 <= ch && ch <= 83) {
            printf("7");
        } else if (84 <= ch && ch <= 86) {
            printf("8");
        } else if (87 <= ch && ch <= 89) {
            printf("9");
        } else {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}