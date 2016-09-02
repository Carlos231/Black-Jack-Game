/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#include "./deck.h"
#include <iostream>

using namespace std;

/*********************************************************************
** FUNCTION: deck
** DESCRIPTION: default constructor to set values of class, makes temp array of cards for 52 cards with the 4 different suits 
** PARAMETERS: none
** PRE-CONDITIONS: value and suit of each card are set up to null
** POST-CONDITIONS: makes 52 cards through temp with value and suit set to different suits and numbers then copies that to 52 cards in stack - deleting the temp array. Shuffles cards at end
** RETURNS: nothing
*********************************************************************/
deck::deck() {
	num_cards = 0;
	count = 0;
	cards = new card[52];
}

/*********************************************************************
** FUNCTION: create_deck
** DESCRIPTION: 
** PARAMETERS: card Singlecard, int num_cards
** PRE-CONDITIONS: num_cards value and singlecard made
** POST-CONDITIONS: num_cards and singlecard updated
** RETURNS: nothing
*********************************************************************/
void deck::create_deck() {
	string suit[4] = { "diamond", "club", "spade", "heart" };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[count].suit = suit[i];
			cards[count].value = (j + 1);
			count++;
		}
	}
}
/*********************************************************************
** FUNCTION: set_num_cards
** DESCRIPTION: update number of cards by subtracting amount everytime a card/cards is taken from deck
** PARAMETERS: int reduce_num
** PRE-CONDITIONS: reduce_num is updated to see how many cards need to be taken from deck
** POST-CONDITIONS: updates number of cards in deck
** RETURNS: nothing
*********************************************************************/
void deck::set_num_cards(const int num_num) {
	num_cards = num_num;
}
///*********************************************************************
//** FUNCTION: print_deck
//** DESCRIPTION: prints all cards in deck
//** PARAMETERS: none
//** PRE-CONDITIONS: deck of cards created
//** POST-CONDITIONS: none
//** RETURNS: nothing
//*********************************************************************/
//void deck::printdeck(){
//	for (int i = 0; i < 52; i++) {
//		cout << "Card [#" << i << "]: ";
//		cards[i].printcard();
//	}
//}
//
/*********************************************************************
** FUNCTION: get_card_from_deck
** DESCRIPTION: retrieve a card from the deck
** PARAMETERS: int x
** PRE-CONDITIONS: card made in deck
** POST-CONDITIONS: prints card
** RETURNS: nothing
*********************************************************************/
card * deck::get_cards_from_deck() {
	return cards;
}

/*********************************************************************
** FUNCTION: get_numcards
** DESCRIPTION: returns private num_cards to public
** PARAMETERS: none
** PRE-CONDITIONS: num_cards in private
** POST-CONDITIONS: num_cards accessible
** RETURNS: num_cards
*********************************************************************/
int deck::get_num_cards() {
	return num_cards;
}

/*********************************************************************
** FUNCTION: shufflecards()
** DESCRIPTION: shuffles deck of cards 1000 times
** PARAMETERS: none
** PRE-CONDITIONS: deck of cards with values made
** POST-CONDITIONS: changes order of cards in deck
** RETURNS: nothing
*********************************************************************/
void deck::shuffle_cards() {
	card temp;
	srand(time(NULL));
	for (int i = 0; i < 999; i++) {
		amt = rand() % 52;
		int amty = rand() % 52;
		temp = cards[amt];
		cards[amt] = cards[amty];
		cards[amty] = temp;
	}
}

/*********************************************************************
** FUNCTION: remove_card
** DESCRIPTION: removes card from deck to keep track of cards being used
** PARAMETERS: none
** PRE-CONDITIONS: array of cards made
** POST-CONDITIONS: size of array of cards decreased by one
** RETURNS: cards[52 - num_cards] (array)
*********************************************************************/
card deck::remove_card() {
	set_num_cards(num_cards);
	num_cards++;
	return cards[52 - num_cards];
}