/*
* A Program that deals a random hand of cards.
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM_SUITS 4
#define NUM_RANK 13

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANK] = {false};

    int num_cards, suit, rank;

    const char suit_code[] = {'C', 'D', 'H', 'S'};
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand: ");

    while(num_cards > 0) {
        suit = rand() % NUM_SUITS;              // Picks a random suit
        rank = rand() % NUM_RANK;               // Pick a random rank

        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;

            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}