/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/

#ifndef HAND_H
#define HAND_H

#include "./card.h"
#include "./deck.h"

//2 cards facing up for players - beginning
class hand {
private:
	card *cards;
	int num_cards;
public:

	//constructor
	hand();

	//Accessor
	int get_num_cards() const;
	card * get_cards_from_deck() const;
	void create_cards(const int);
	
	//Mutator
	void set_cards(const int, const card);
	void set_num_cards(int);
	void set_dealer(); //set deck

	//BIG 3
	hand(const hand &); //Copy Constructor
	~hand(); //destructor
	void operator = (const hand &); //assignment operator overload	

	//game stuff
	void show_cards();
	void print_hand();
	int cards_total();
	void add_card(card);
	void remove_card(); //remove from deck
};

#endif