/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#ifndef DECK_H
#define DECK_H

#include "./card.h"
#include <ctime>
#include <cstdlib>

class deck {
private:
	card *cards;
	int num_cards;
	int count;
	int amt;
public:
	//Constructor
	deck();
	
	//Mutator			
	void set_cards();
	void set_num_cards(const int); //Set the number of cards in the deck
	void create_deck(); //creates the deck in ascending order

	//Accessor
	int get_num_cards();
	card *get_cards_from_deck();

	//game stuff
	void shuffle_cards(); //shuffles the deck
	card remove_card();
	
};
#endif