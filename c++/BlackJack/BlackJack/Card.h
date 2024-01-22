#pragma once
#include <iostream>
using namespace std;

class Card
{
public:
	Card();
	int suit;
	int number;
	int value;
	bool isFace;
	string displaySuit;
	string displayFace;
	int displayNum;
	string setCard(int newSuit,int  newNumber);
	void getCard();
};