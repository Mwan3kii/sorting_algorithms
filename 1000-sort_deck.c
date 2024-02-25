#include "deck.h"
/**
 * _strcmp - Compares two strings
 * @s1: The first string to be compared.
 * @s2: The second string to be compared
 * Return: Positive byte difference if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * get_card_value - Get the numerical value of a card
 * @card: A pointer to a deck_node_t card
 *
 * Return: The numerical value of the card
 */
char get_card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}
/**
 * sort_deck_kind - Sort a deck of cards from spades to diamonds
 * @deck: A pointer to deck_node_t doubly-linked list
 */
void sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterr, *temp, *insert;

	for (iterr = (*deck)->next; iterr != NULL; iterr = temp)
	{
		temp = iterr->next;
		insert = iterr->prev;
		while (insert != NULL && insert->card->kind > iterr->card->kind)
		{
			insert->next = iterr->next;
			if (iterr->next != NULL)
				iterr->next->prev = insert;
			iterr->prev = insert->prev;
			iterr->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterr;
			else
				*deck = iterr;
			insert->prev = iterr;
			insert = iterr->prev;
		}
	}
}
/**
 * sort_deck_value - Sort a deck of cards sorted from ace to king
 * @deck: A pointer to deck_node_t doubly-linked list
 */
void sort_deck_value(deck_node_t **deck)
{
	deck_node_t *insert, *iterr, *temp;

	for (iterr = (*deck)->next; iterr != NULL; iterr = temp)
	{
		temp = iterr->next;
		insert = iterr->prev;
		while (insert != NULL &&
			insert->card->kind == iterr->card->kind &&
			get_card_value(insert) > get_card_value(iterr))
		{
			insert->next = iterr->next;
			if (iterr->next != NULL)
				iterr->next->prev = insert;
			iterr->prev = insert->prev;
			iterr->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterr;
			else
				*deck = iterr;
			insert->prev = iterr;
			insert = iterr->prev;
		}
	}
}
/**
 * sort_deck - Sort a deck of cards from ace to king and spades to diamond
 * @deck: A pointer to deck_node_t doubly-linked list
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	sort_deck_kind(deck);
	sort_deck_value(deck);
}
