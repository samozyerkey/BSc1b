#pragma once
#include <iostream>
using namespace std;
class Deck
{
public:
	Deck();
	void resetDeck();
	void shuffle();
	void pull(bool player);
	void Display(bool showDealer);
};