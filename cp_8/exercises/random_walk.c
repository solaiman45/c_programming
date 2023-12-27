/*
* A program that generates a random walk across a 10x10 array.
*
* Left_move = 0
* Up_move = 1
* Right_move = 2
* Down_move = 3
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COLUMN 10

int main(void)
{
    // Creating the initial 10x10 board for random walk.
    char array[ROW][COLUMN];


    // Initialising the array to be '.' character for each position.
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            array[i][j] = '.';
        }
    }

    // Starting position for random walk (0,0)
    int pos_x = 0;
    int post_y = 0;
    array[pos_x][post_y] = 'A';


    // Generating a random number between 0 and 3.
    int direction_movement = 0;
    srand((unsigned) time(NULL));
    direction_movement = rand() % 4;

    if (direction_movement == 0) {
        pos_x = pos_x;
        post_y = post_y - 1;
    } else if (direction_movement == 2) {
        pos_x = pos_x;
        post_y = post_y + 1;
    } else if (direction_movement == 1) {
        pos_x = pos_x - 1;
        post_y = post_y;
    } else if (direction_movement == 3) {
        pos_x = pos_x + 1;
        post_y = post_y;
    }

    


    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf(" %c ", array[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}