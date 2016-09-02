/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#ifndef DEALER_H
#define DEALER_H

#include "./hand.h"

class dealer {
private:
	hand d_hand;
	int card_total;
public:
	//constructors
	dealer();
	
	//accessors
	hand *get_dealer_hand();
	
	//mutators
	void set_dealer_card_total(int);
	void set_dealer_hand(hand);
	
	//game stuff
	void print_dealer_hand();
	void initialize();
	void reveal();
	int calc_card_total();
	int get_dealer_card_total();

	//destructors
	//none needed
};

#endif