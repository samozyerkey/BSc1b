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
	void Display(bool showDealer, bool refresh);
	bool SwapAceVal(bool player, bool toOne, bool manual);
	int getTotal(bool player);
	int GameStatus(bool playerEnd, bool bust);
};