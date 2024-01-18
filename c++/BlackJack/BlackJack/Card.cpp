#include "Card.h"
#include <iostream>
using namespace std;
Card::Card() {
	suit = rand() % 4;
	number = rand() % 13;
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
	if (newSuit >= 0) {
		suit = newSuit-1;
	}
	if (newNumber >= 0) {
		number = newNumber-1;
	}
	if (number == 0) {
		value = 11;
	}
	if (number > 8) {
		value = 10;
	}
	else {
		value = number + 1;
	}
	return displaySuit;
}

void Card::getCard() {
	if (suit == 0) {
		displaySuit = "Diamonds";
	}
	if (suit == 1) {
		displaySuit = "Hearts";
	}
	if (suit == 2) {
		displaySuit = "Spades";
	}
	if (suit == 3) {
		displaySuit = "Clubs";
	}
	if (number == 0) {
		displayFace = "Ace";
		isFace = true;
	}
	else if (number == 10) {
		displayFace = "Jack";
		isFace = true;
	}
	else if (number == 11) {
		displayFace = "Queen";
		isFace = true;
	}
	else if (number == 12) {
		displayFace = "King";
		isFace = true;
	}
	else {
		displayNum = number + 1;
		isFace = false;
	}
	if (isFace == false) {
		cout << "The " << displayNum << " of " << displaySuit << " ";
	}
	else if (isFace == true) {
		cout << "The " << displayFace << " of " << displaySuit << " ";
	}

}