/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#include "./player.h"
#include <iostream>

using namespace std;

/*********************************************************************
** FUNCTION: player
** DESCRIPTION: set values of player to null states
** PARAMETERS: none
** PRE-CONDITIONS: garbage in variables
** POST-CONDITIONS: variables set to null states
** RETURNS: nothing
*********************************************************************/
player::player() {
	playing_total = 1000;
	card_total = 0;
	bet = 0;
}

/*********************************************************************
** FUNCTION: set_playing_total
** DESCRIPTION: retrieves playing_total
** PARAMETERS: none
** PRE-CONDITIONS: palying_total private
** POST-CONDITIONS: access to playing_total
** RETURNS: playing_total
*********************************************************************/
int player::get_playing_total() {
	return playing_total;
}

/*********************************************************************
** FUNCTION: set_card_total
** DESCRIPTION: retrieves card_total
** PARAMETERS: none
** PRE-CONDITIONS: card_total private
** POST-CONDITIONS: access to card_total
** RETURNS:card_total
*********************************************************************/
int player::get_card_total() {
	return card_total;
}

/*********************************************************************
** FUNCTION: get_hand
** DESCRIPTION: retrieves hand array
** PARAMETERS: none
** PRE-CONDITIONS: hand array private
** POST-CONDITIONS: access to hand array
** RETURNS: p_hand
*********************************************************************/
hand &player::get_player_hand() {
	return p_hand;
}

/*********************************************************************
** FUNCTION: get_hand
** DESCRIPTION: returns a reference to p_hand
** PARAMETERS: none
** PRE-CONDITIONS: hand array private
** POST-CONDITIONS: access to hand array
** RETURNS: &p_hand address
*********************************************************************/
void player::set_p_hand(hand p) {
	p_hand = p;
}
/*********************************************************************
** FUNCTION: set_card_total
** DESCRIPTION: updates card total
** PARAMETERS: int total
** PRE-CONDITIONS: garbage in variables
** POST-CONDITIONS: variables set to null states
** RETURNS: nothing
*********************************************************************/
void player::set_card_total(int total) {
	card_total = total;
}

/*********************************************************************
** FUNCTION: set_bet
** DESCRIPTION: updates bet amount
** PARAMETERS: int amount
** PRE-CONDITIONS: updates bet amount
** POST-CONDITIONS: bet amount updated with player
** RETURNS: nothing
*********************************************************************/
void player::set_bet(int player_bet) {
	bet = player_bet;
}

/*********************************************************************
** FUNCTION: print_hand
** DESCRIPTION: prints hand
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void player::print_hand() {
	p_hand.print_hand();
}

/*********************************************************************
** FUNCTION: winner
** DESCRIPTION: player keeps their bet
** PARAMETERS: none
** PRE-CONDITIONS: playing total set
** POST-CONDITIONS: player total is updated
** RETURNS: nothing
*********************************************************************/
void player::winner() {
	playing_total = playing_total + bet;
}

/*********************************************************************
** FUNCTION: loser
** DESCRIPTION: player looses their bet
** PARAMETERS: none
** PRE-CONDITIONS: playing total set
** POST-CONDITIONS: player total is updated
** RETURNS: nothing
*********************************************************************/
void player::loser() {
	playing_total = playing_total - bet;
}

/*********************************************************************
** FUNCTION: blackjack
** DESCRIPTION: player keeps their bet + 1.5% of that
** PARAMETERS: none
** PRE-CONDITIONS: playing total set
** POST-CONDITIONS: player total is updated
** RETURNS: nothing
*********************************************************************/
void player::blackjack() {
	playing_total = playing_total + (bet * 1.5);
}

/*********************************************************************
** FUNCTION: calc_card_total
** DESCRIPTION: add up cards in hand
** PARAMETERS: none
** PRE-CONDITIONS: cards have values
** POST-CONDITIONS: doesnt change anything
** RETURNS: total
*********************************************************************/
int player::calc_card_total() {
	int total = p_hand.cards_total();
	return total;
}