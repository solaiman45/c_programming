/*
* A program that prompts for five quiz grades for each of five students,
* then computes the total and average score for each student,
* and the average, high and low score for each quiz.
*/


#include <stdio.h>


#define STUDENTS 5
#define QUIZ_GRADES 5

int main(void)
{
    int array[STUDENTS][QUIZ_GRADES] = {0};
    int total_score_students[STUDENTS][1] = {0};
    int average_score_students[STUDENTS][1] = {0};

    int total_score = 0;
    float average_score = 0.0f;
    int high_score = 0;
    int low_score;

    // Reading student grades into the array
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d grades: ", i+1);

        for (int j = 0; j < QUIZ_GRADES; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    
    printf("\n");

    // Calculates total score for each student
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < QUIZ_GRADES; j++) {
            total_score_students[i][0] += array[i][j];
        }
    }

    // Calculates average score for each student
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < 1; j++) {
            average_score_students[i][0] = total_score_students[i][0] / QUIZ_GRADES;
        }
    }

    // Prints total score for each student
    printf("Total Scores");
    printf("\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d total score: %d", i+1, total_score_students[i][0]);
        printf("\n");
    }
    printf("\n");

    // Prints Average score for each student
    printf("Average Scores");
    printf("\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Studen %d average score: %d", i+1, average_score_students[i][0]);
        printf("\n");
    }

    printf("\n");

    // Calculates average score for the quizes
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < QUIZ_GRADES; j++) {
            total_score += array[i][j];
        }
    }
    average_score = (float) total_score / (STUDENTS * QUIZ_GRADES);
    printf("Average Score: %.2f", average_score);
    printf("\n");

    // Calculates highest score
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < QUIZ_GRADES; j++) {
            if (array[i][j] > high_score) {
                high_score = array[i][j];
            }
        }
    }
    printf("Highest Score: %d", high_score);
    printf("\n");

    // Calculates lowest core
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < QUIZ_GRADES; j++) {
            low_score = array[i][j];

            if (array[i][j] < low_score) {
                low_score = array[i][j];
            }
        }
    }
    printf("Lowest Score: %d", low_score);
    printf("\n");
    
    return 0;
}