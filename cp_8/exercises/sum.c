/*
* A program that reads a 5x5 array of integers and then prints the row and column sums.
*/


#include <stdio.h>


#define ROW 5
#define COLUMN 5

int main(void)
{
    int array[ROW][COLUMN] = {0};
    int row_sum[ROW] = {0};
    int column_sum[COLUMN] = {0};

    // Prompting user for input
    for (int i = 0; i < ROW; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < COLUMN; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // summing the rows
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            row_sum[i] += array[i][j];
        }
    }

    // summing the columns
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            column_sum[i] += array[j][i];
        }
    }

    // printing row sums
    printf("Row totals: ");
    for (int i = 0; i < ROW; i++) {
        printf("%d ", row_sum[i]);
    }
    printf("\n");

    // printing column sums
    printf("Column totals: ");
    for (int i = 0; i < COLUMN; i++) {
        printf("%d ", column_sum[i]);
    }
    printf("\n");

    return 0;
}