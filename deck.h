#ifndef DECK_H
#define DECK_H value

typedef enum kind_e
{
    SPADE,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * card_s structure - represents a playing card
 *
 * @value: the face value of the card, ranging from Ace to King
 * @kind: the suit of the card, which can be SPADE, HEART, CLUB, or DIAMOND
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * deck_node_s structure - represents a node in a deck of cards
 *
 * @card: a pointer to the card stored in the node
 * @prev: a pointer to the previous node in the deck
 * @next: a pointer to the next node in the deck
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_value(deck_node_t **deck);
void sort_kind(deck_node_t **deck);
void swap(deck_node_t *temp, int i);
int check_value(const char *string);

/**
 * sort_deck - sorts a deck of cards using two criteria: face value and suit
 *
 * @deck: a double pointer to the head of the deck to sort
 */
void sort_deck(deck_node_t **deck);

#endif /* ifndef DECK_H */
