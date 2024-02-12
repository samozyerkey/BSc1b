#include "Card.h"
#include <iostream>
using namespace std;
Card::Card() {
	suit = 0;
	number = 0;
	if (number == 0) {
		value = 11;
	}
	if (number > 8) {
		value = 10;
	}
	else {
		value = number + 1;
	}
}

string Card::setCard(int newSuit, int newNumber) {
	if (newSuit > 0) {
		suit = newSuit-1;
	}
	if (suit < 2) {
		colour = false;
	}
	if (suit > 1) {
		colour = true;
	}
	if (newNumber > 0) {
		number = newNumber-1;
	}
	if (number == 0) {
		value = 11;
	}
	else if (number >= 9) {
		value = 10;
	}
	else {
		value = number + 1;
	}
	return displaySuit;
}