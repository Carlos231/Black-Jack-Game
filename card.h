/******************************************************
** Program: play_game.cpp
** Author: Carlos Lopez-Molina
** Date: 04/16/2016
** Description: Play Blackjack 21 with either 1 vs computer or againts other oponents.
** Input: Players with bet money
** Output: Players get dealt cards, winner is who total card values equal 21 or closest to 21.
******************************************************/
//interface file - Function declarations
#ifndef CARD_H //check to see if has been declared already, if not then declare
#define CARD_H

#include <iostream> 
#include <string>

using namespace std;

//card struct
struct card {
	int value; //1-13
	string suit; //heart, club, diamond, spade
};

#endif