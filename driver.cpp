/******************************************************
** Program: blackjack
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#include "./game.h"

using namespace std;

int main() {
	int players = 0;
	game Blackjack; //game struct
	deck cards; //declare card struct
	
	cout << "Welcome to the game BlackJack 21!" << endl;
	cout << "Both players start out with a total of $1000." << endl;
	cout << "How many players will be palying? ";
	cin >> players;

	Blackjack.set_players(players);
	Blackjack.get_bet();
	Blackjack.deal_cards();
	Blackjack.player_hit_hold();
	Blackjack.dealer_hit_hold();
	
	return 0;
}
