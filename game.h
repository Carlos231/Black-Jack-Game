/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#ifndef GAME_H
#define GAME_H

#include "./dealer.h"
#include "./player.h"
#include "./deck.h"

class game {
private:
	deck cards;
	player *players;
	dealer game_dealer;
	int num_players;
public:
	//constructors
	game();
	
	//mutators
	void set_cards(deck);
	void set_players(int);
	void set_bet();
	void set_game_dealer();
	void create_players(const int);
	void set_game_dealer(dealer);

	//accessors
	deck get_cards_from_deck();
	dealer get_game_dealer();
	player *get_players();
	int get_num_players();
	void get_bet();
	
	//destructors
	~game();
	
	//game stuff
	void deal_cards();
	void player_hit_hold();
	void dealer_hit_hold();
	void create_players();
	hand *create_hand();
	bool check_bet(int, int);
};

#endif