#pragma once
#include <iostream>
using namespace std;
class Deck
{
public:
	Deck();
	string newCard();
	int deck[3][12];
};