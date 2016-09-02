/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#include "dealer.h"

/*********************************************************************
** FUNCTION: dealer
** DESCRIPTION: default constructor sets card total to 0
** PARAMETERS: none
** PRE-CONDITIONS: card_total garbage
** POST-CONDITIONS: card total null state
** RETURNS: nothing
*********************************************************************/
dealer::dealer() {
	card_total = 0;
}

/*********************************************************************
** FUNCTION: get_dealer_hand_total
** DESCRIPTION: retrieve address of d_hand
** PARAMETERS: none
** PRE-CONDITIONS: d_hand private to class
** POST-CONDITIONS:d_hand accessible
** RETURNS: d_hand
*********************************************************************/
int dealer::get_dealer_card_total() {
	return card_total;
}
/*********************************************************************
** FUNCTION: print_dealer_hand
** DESCRIPTION: output the dealers hand
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void dealer::print_dealer_hand() {
	d_hand.print_hand();
}
///*********************************************************************
//** FUNCTION: set_dealer_card_total
//** DESCRIPTION: updates card total for dealer
//** PARAMETERS: int card_total
//** PRE-CONDITIONS: card total accessible
//** POST-CONDITIONS: updated card total
//** RETURNS: nothing
//*********************************************************************/
void dealer::set_dealer_card_total(int num) {
	card_total = num;
}

/*********************************************************************
** FUNCTION: set_dealer_hand
** DESCRIPTION: set dealers hand with cards
** PARAMETERS: int card_total
** PRE-CONDITIONS: card total accessible
** POST-CONDITIONS: updated card total
** RETURNS: nothing
*********************************************************************/
void dealer::set_dealer_hand(hand h) {
	d_hand = h;
}

/*********************************************************************
** FUNCTION: get_dealer_hand
** DESCRIPTION: gets dealers hand with cards
** PARAMETERS: none
** PRE-CONDITIONS: card total private
** POST-CONDITIONS: card public
** RETURNS: nothing
*********************************************************************/
hand *dealer::get_dealer_hand() {
	return &d_hand;
}

/*********************************************************************
** FUNCTION: calc_card_total
** DESCRIPTION: returns cards total
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: d_hand.cards_total();
*********************************************************************/
int dealer::calc_card_total() {
	return d_hand.cards_total();
}

/*********************************************************************
** FUNCTION: initialize
** DESCRIPTION: set dealers hand with cards
** PARAMETERS: none
** PRE-CONDITIONS: dealers hand has garbage
** POST-CONDITIONS: cards set in hand
** RETURNS: nothing
*********************************************************************/
void dealer::initialize() {
	d_hand.set_dealer();
}

/*********************************************************************
** FUNCTION: reveal
** DESCRIPTION: shows both dealers cards
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: changes nothing
** RETURNS: nothing
*********************************************************************/
void dealer::reveal() {
	d_hand.print_hand();
}