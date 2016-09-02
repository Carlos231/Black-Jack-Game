/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
#include "./hand.h"

/*********************************************************************
** FUNCTION: hand
** DESCRIPTION: default constructor to set variables of hand to null state
** PARAMETERS: none
** PRE-CONDITIONS: cards and num_cards have garbage
** POST-CONDITIONS: cards and num_cards set to null states
** RETURNS: nothing
*********************************************************************/
hand::hand() {
	cards = NULL;
	num_cards = 0;
}
/*********************************************************************
** FUNCTION: hand
** DESCRIPTION: default constructor to set variables of hand to null state
** PARAMETERS: const hand &other
** PRE-CONDITIONS: cards null
** POST-CONDITIONS: cards set to copy "other" array
** RETURNS: nothing
*********************************************************************/
////copy of cards array to copy in heap
hand::hand(const hand &other) {
	cards = new card[other.num_cards];
	for (int i = 0; i < other.num_cards; i++)
		cards[i] = other.cards[i];
	num_cards = other.num_cards;
}

/*********************************************************************
** FUNCTION: set_cards
** DESCRIPTION: sets card in card slot to singlecard
** PARAMETERS: const int slot, const card singlecard
** PRE-CONDITIONS: card array set up
** POST-CONDITIONS: card array in spot updated to singlecard values
** RETURNS: nothing
*********************************************************************/
void hand::set_cards(const int num_cards, const card c) {
	cards[num_cards] = c; //num is the indexer for the card array and c is the card you're getting
}

/*********************************************************************
** FUNCTION: set_num_cards
** DESCRIPTION: updates num_cards
** PARAMETERS: int num
** PRE-CONDITIONS: none
** POST-CONDITIONS: num_cards updated with new values
** RETURNS: nothing
*********************************************************************/
void hand::set_num_cards(int nc) {
	num_cards = nc;
}

/*********************************************************************
** FUNCTION: operator
** DESCRIPTION: assignment operator overload - default to set up cards in hand
** PARAMETERS: const hand &other
** PRE-CONDITIONS: default assignment operator to set up hand
** POST-CONDITIONS: hand set up
** RETURNS: nothing
*********************************************************************/
void hand::operator = (const hand &other) {
	if (cards != NULL)
		delete[] cards;
	for (int i = 0; i < num_cards; i++)
		other.cards[i] = cards[i];
	num_cards = other.num_cards;
}

/*********************************************************************
** FUNCTION: printhand
** DESCRIPTION: outputs the cards in the players hand
** PARAMETERS: none
** PRE-CONDITIONS: hand with cards made
** POST-CONDITIONS: outputs the values
** RETURNS: nothing
*********************************************************************/
void hand::print_hand() {
	for (int i = 0; i < num_cards; i++) {
		if (cards[i].value == 1)
			cout << "Ace of " << cards[i].suit << endl;
		else if (cards[i].value == 11)
			cout << "Jack of " << cards[i].suit << endl;
		else if (cards[i].value == 12)
			cout << "Queen of " << cards[i].suit << endl;
		else if (cards[i].value == 13)
			cout << "King of " << cards[i].suit << endl;
		else
			cout << cards[i].value << " of " << cards[i].suit << endl;

	}
}

/*********************************************************************
** FUNCTION: ~hand
** DESCRIPTION: deallocates memory from cards of hand
** PARAMETERS: none
** PRE-CONDITIONS: cards array in heap has been set
** POST-CONDITIONS: no memory leaks
** RETURNS: nothing
*********************************************************************/
hand::~hand() {
	delete[] cards;
}

/*********************************************************************
** FUNCTION: create_cards
** DESCRIPTION: creates cards for players hand
** PARAMETERS: const int num_cards
** PRE-CONDITIONS: num_cards has correct value
** POST-CONDITIONS: new array of cards made
** RETURNS: nothing
*********************************************************************/
void hand::create_cards(const int num) {//left here 
	num_cards = num;
	cards = new card[num_cards];
}

/*********************************************************************
** FUNCTION: get_cards_from_deck
** DESCRIPTION: gets hand array and returns the address
** PARAMETERS: none
** PRE-CONDITIONS: cards made
** POST-CONDITIONS: none
** RETURNS: cards
*********************************************************************/
card *hand::get_cards_from_deck() const {
	return cards;
}

/*********************************************************************
** FUNCTION: card_totals()
** DESCRIPTION: calculate and set values to cards
** PARAMETERS: none
** PRE-CONDITIONS: cards set
** POST-CONDITIONS: read card values
** RETURNS: total
*********************************************************************/
int hand::cards_total() { //
	int total = 0;
	for (int i = 0; i < num_cards; i++) {
		if (cards[i].value >= 10) {
			total = total + 10;
		}
		else if (cards[i].value == 1) {
			total = total + 11;
		}
		else {
			total = total + cards[i].value;
		}
	}
	return total;
}


/*********************************************************************
** FUNCTION: get_num_cards
** DESCRIPTION: returns num_cards
** PARAMETERS: none
** PRE-CONDITIONS: num_cards private to class
** POST-CONDITIONS: num_cards accessible
** RETURNS: num_cards
*********************************************************************/
int hand::get_num_cards() const {
	return num_cards;
}

/*********************************************************************
** FUNCTION: set_dealer
** DESCRIPTION: set up dealer
** PARAMETERS: none
** PRE-CONDITIONS: class made
** POST-CONDITIONS: class made
** RETURNS: nothing
*********************************************************************/
void hand::set_dealer() {
	for (int i = 1; i < num_cards; i++) {
		if (cards[i].value == 1)
			cout << "Ace" << cards[i].suit << endl;
		else if (cards[i].value == 11)
			cout << "Jack" << cards[i].suit << endl;
		else if (cards[i].value == 12)
			cout << "Queen" << cards[i].suit << endl;
		else if (cards[i].value == 13)
			cout << "King" << cards[i].suit << endl;
		else
			cout << cards[i].value << " of  " << cards[i].suit << endl;
	}
}

/*********************************************************************
** FUNCTION: add_card
** DESCRIPTION: updated hand array with new card that was added
** PARAMETERS: card newHand
** PRE-CONDITIONS: hand array made with value
** POST-CONDITIONS: 1 card added to hand array
** RETURNS: nothing
*********************************************************************/
void hand::add_card(card newHand) {
	card *temp;
	num_cards++;
	set_num_cards(num_cards);
	temp = cards;
	cards = new card[num_cards];
	for (int i = 0; i < num_cards - 1; i++)
		cards[i] = temp[i];
	delete[] temp;
	cards[num_cards - 1] = newHand;
}