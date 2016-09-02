/******************************************************
 ** Program: play_game.cpp
 ** Author: Carlos Lopez-Molina
 ** Date: 04/16/2016
 ** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
 ** Input: Players with bet money
 ** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
// ******************************************************/
#include "./game.h"
#include <iostream>

using namespace std;

/*********************************************************************
 ** FUNCTION: game
 ** DESCRIPTION: default constructor sets variables to null states
 ** PARAMETERS: none
 ** PRE-CONDITIONS: variables contain garbage
 ** POST-CONDITIONS: variables set to null states
 ** RETURNS: nothing
 *********************************************************************/
game::game() {
	num_players = 0;
	players = NULL;
}

/*********************************************************************
 ** FUNCTION: getcards
 ** DESCRIPTION: get cards from deck
 ** PARAMETERS: none
 ** PRE-CONDITIONS: cards private
 ** POST-CONDITIONS: cards accessible
 ** RETURNS: cards
 *********************************************************************/
deck game::get_cards_from_deck() {
	return cards;
}

/*********************************************************************
 ** FUNCTION: getplayers
 ** DESCRIPTION: get players
 ** PARAMETERS: none
 ** PRE-CONDITIONS: players private
 ** POST-CONDITIONS: players accessible
 ** RETURNS: players
 *********************************************************************/
player *game::get_players() {
	return players;
}

/*********************************************************************
 ** FUNCTION: get_game_dealer
 ** DESCRIPTION: get game_dealer
 ** PARAMETERS: none
 ** PRE-CONDITIONS: game_dealer private
 ** POST-CONDITIONS: game_dealer accessible
 ** RETURNS: game_dealer
 *********************************************************************/
dealer game::get_game_dealer() {
	return game_dealer;
}

/*********************************************************************
** FUNCTION: set_cards
** DESCRIPTION: SETS CARDS
** PARAMETERS: DECK C
** PRECONDTIION: DECK HAS BEEN MADE
** POSTCONDITHIUFKC: CARDS HAS BEEN SET
** RETURNS: NOTHING
*********************************************************************/
void game::set_cards(deck nCards) {
	cards = nCards;
}

/*********************************************************************
 ** FUNCTION: set_players
 ** DESCRIPTION: update array with array of players
 ** PARAMETERS: none
 ** PRE-CONDITIONS: pointer player made
 ** POST-CONDITIONS: array with players
 ** RETURNS: nothing
 *********************************************************************/
void game::set_players(int num) {
	num_players = num;
	create_players();
}

/*********************************************************************
 ** FUNCTION: create_players
 ** DESCRIPTION: update array with array of players
 ** PARAMETERS: none
 ** PRE-CONDITIONS: pointer player made
 ** POST-CONDITIONS: array with players
 ** RETURNS: nothing
 *********************************************************************/
void game::create_players() {
	players = new player[num_players];
}

/*********************************************************************
** FUNCTION: get_bet
** DESCRIPTION: get bet amounts from the players
** PARAMETERS: none
** PRE-CONDITIONS: amount set to 0
** POST-CONDITIONS: new bet amount saved
** RETURNS: nothing
*********************************************************************/
void game::get_bet() {
	int bet;
	bool valid = true;
	while (valid) {
		for (int i = 0; i < num_players; i++) {
			cout << "Player " << i + 1 << " enter your bet: ";
			cin >> bet;
			valid = check_bet(bet, i);
			if (valid == true) {
				cout << "Try again, you dont have enough money!" << endl;
			}
			else
				players[i].set_bet(bet);
		}
	}
}

/*********************************************************************
** FUNCTION: check_bet
** DESCRIPTION: check to see if bet is less than total amount
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
bool game::check_bet(int bet, int player) {
	if (bet > 0 && bet <= players[player].get_playing_total()) {
		return false;
	}
	return true;
}

/*********************************************************************
** FUNCTION: set_game_dealer
** DESCRIPTION: set the dealer up
** PARAMETERS: dealer guy
** PRE-CONDITIONS: none
** POST-CONDITIONS: dealer updated with new dealer
** RETURNS: nothing
*********************************************************************/
void game::set_game_dealer(dealer guy) {
	game_dealer = guy;
}

/*********************************************************************
 ** FUNCTION: deal_cards
 ** DESCRIPTION: gives cards to players and dealer
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: creates arrays for players and dealers
 ** RETURNS: nothing
 *********************************************************************/
void game::deal_cards() {
	cards.create_deck();
	cards.shuffle_cards();
	//give each player two cards
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_players; j++) {
			players[j].get_player_hand().add_card(cards.remove_card());
		}
		game_dealer.get_dealer_hand()->add_card(cards.remove_card()); //dealer gets cards in this loop
	}
	//output the data for each player
	for (int i = 0; i < num_players; i++) {
		cout << endl;
		cout << "Player " << i + 1 << ": " << endl;
		cout << " Players total money: " << players[i].get_playing_total() << endl;
		players[i].print_hand();
		cout << "Player " << i + 1 << " card total: " << players[i].calc_card_total() << endl;
	}
	cout << endl;
	cout << "Dealer's Cards: " << endl;
	cout << "Hidden card" << endl;
	game_dealer.initialize();
	cout << endl;
}
/*********************************************************************
 ** FUNCTION: player_hit_hold
 ** DESCRIPTION: deal out the cards
 ** PARAMETERS: none
 ** PRE-CONDITIONS: player array set
 ** POST-CONDITIONS: players deallocated
 ** RETURNS: nothing
 *********************************************************************/
void game::player_hit_hold() {
	int choice;
	for (int i = 0; i < num_players; i++) {
		while (players[i].calc_card_total() < 21) {
			cout << "player " << i+1 << " card total:" << players[i].calc_card_total() << endl;
			cout << "Hit (1) or Pass(0): ";
			cin >> choice;
			if (choice == 1) {
				cout << endl;
				players[i].get_player_hand().add_card(cards.remove_card());
				cout << endl;
				players[i].print_hand();
			}
			else
				break;
		}
	}
}

/*********************************************************************
** FUNCTION: dealer_hit_hold
** DESCRIPTION: sees if dealer needs to hit or has enough points
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: changes dealers hand amount
** RETURNS: nothing
*********************************************************************/
void game::dealer_hit_hold() {
	cout  << endl;
	cout << "Dealer's Hand: " << endl;
	game_dealer.reveal();
	cout << endl;
	while (game_dealer.calc_card_total() < 17) {
		game_dealer.get_dealer_hand()->add_card(cards.remove_card());
		cout << "Dealer will get another card because total is less than 17." << endl;
	}
	if (game_dealer.calc_card_total() > 21) { //for when dealer goes over 21
		game_dealer.set_dealer_card_total(0);
	}
	cout << "Dealers total card vlaues: " << game_dealer.calc_card_total() << endl;
	for (int i = 0; i < num_players; i++) {
		if (game_dealer.calc_card_total() > players[i].calc_card_total()) {
			cout << "Player " << i + 1 << " lost!" << endl;
			players[i].loser();
		}
		else if (game_dealer.calc_card_total() < players[i].calc_card_total()) {
			cout << "Player " << i + 1 << " won! " << endl;
			players[i].winner();
		}
		else if (players[i].calc_card_total() == 21) {
			cout << "Player " << i + 1 << "BLACKJACK! " << endl;
			players[i].blackjack();
		}
		else {
			cout << "Player " << i + 1 << " tied with the dealer!" << endl;
			players[i].loser();
		}
		cout << endl;
	cout << "Dealer card total: " << game_dealer.calc_card_total() << endl;
	for (int i = 0; i < num_players; i++) {
		cout << "Player " << i + 1 << " card total: " << players[i].calc_card_total() << " and total money: $" << players[i].get_playing_total() << endl;
	}
	}
}

/*********************************************************************
** FUNCTION: ~game
** DESCRIPTION: deallocate player array - avoid memory leaks
** PARAMETERS: none
** PRE-CONDITIONS: player array set
** POST-CONDITIONS: players deallocated
** RETURNS: nothing
*********************************************************************/
game::~game() {
	delete[] players;
}