#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valtoi(const char *value);
void sort_deck(deck_node_t **deck);

/**
 * compare - comparison function for playing cards for use with qsort
 * @l: left card
 * @r: right card
 *
 * Return: 1 if `l` is greater than `r`, -1 if `r` is greater than `l`,
 * 0 if they are equal.
 */
int compare(const void *l, const void *r)
{
	const deck_node_t *left = *(const deck_node_t **)l;
	const deck_node_t *right = *(const deck_node_t **)r;
	int lv, rv;

	if (left->card->kind > right->card->kind)
		return (1);
	if (left->card->kind < right->card->kind)
		return (-1);
	lv = valtoi(left->card->value);
	rv = valtoi(right->card->value);
	if (lv > rv)
		return (1);
	if (lv < rv)
		return (-1);
	return (0);
}

/**
 * valtoi - convert card value to integer for comparison
 * @value: string representation of card value
 *
 * Return: integer representation of `value`.
 */
int valtoi(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "Jack") == 0)
		return (11);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "King") == 0)
		return (13);
	return (atoi(value));
}

/**
 * sort_deck - function to sort deck of cards in order of suit and value
 * @deck: pointer to head of linked list of 52 card deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *deck_array[54], *head;
	size_t i;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	head = *deck;
	deck_array[0] = NULL;
	for (i = 1; i < 53 && head != NULL; i++)
	{
		deck_array[i] = head;
		head = head->next;
	}
	deck_array[i] = NULL;
	qsort(deck_array + 1, 52, sizeof(deck_array[1]), compare);
	for (i = 1; i < 53; i++)
	{
		deck_array[i]->prev = deck_array[i - 1];
		deck_array[i]->next = deck_array[i + 1];
	}
	*deck = deck_array[1];
}
