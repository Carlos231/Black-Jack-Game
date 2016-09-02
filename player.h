/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "./hand.h"

class player {
private:
	hand p_hand; //the two cards + any more they choose to get
	int playing_total; //total money they have for game
	int card_total; //cards added up
	int bet; //how much betting each round
public:
	//must have constructors
	player();

	//mutators
	void set_playing_total();
	void set_bet(int);
	void set_p_hand(hand);
	void set_initial_hand(deck &);
	void set_card_total(int);

	// accessors
	hand &get_player_hand();
	hand *get_hand();
	int get_playing_total();
	int get_card_total();
	//void get_bet();

	//game stuff
	void print_hand();
	void winner();
	void loser();
	void blackjack();
	int calc_card_total();
	
	//destructors
	//none needed
};

#endif