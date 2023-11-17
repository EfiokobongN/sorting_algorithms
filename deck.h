#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * enum kind_e - enum of the 4 card colors
 *
 * @SPADE: Represents the color spad value of 0
 * @HEART: Represents the color heart value of 1
 * @CLUB: Represents the color club value of 2
 * @DIAMOND: Represents the color diamond value of 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Respresents a Playing card
 *
 * @value: Value of the card,
 * From "Ace" to "King"
 * @kind: Kind of the card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a card in a deck
 *
 * @card: Pointer to the card associated with this node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* DECK SORT */

void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
