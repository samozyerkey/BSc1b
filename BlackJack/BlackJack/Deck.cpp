#include "Deck.h"
#include <iostream>
#include "Card.h"
using namespace std;
Card deck[52];
Card playerDeck[11];
Card dealerDeck[11];
string displaySuits[4];
string displayNumbers[13];

Deck::Deck() {
	int n = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			Card card = Card::Card();
			card.setCard(i, j);
			deck[n] = { card };
			n++;
		}
	}
}

int playerI=0;
void Deck::pull(bool player) {
	if (player == true) {
		playerDeck[playerI] = deck[0];
		playerI++;
	}
	for (int i = 0; i < 52; i++) {
		int j = i + 1;
		deck[i] = deck[j];
	}
}

void Deck::Display(bool showDealer) {
	displaySuits[0] = "D| ";
	displaySuits[1] = "H| ";
	displaySuits[2] = "S| ";
	displaySuits[3] = "C| ";
	displayNumbers[0] = "| A ";
	displayNumbers[1] = "| 2 ";
	displayNumbers[2] = "| 3 ";
	displayNumbers[3] = "| 4 ";
	displayNumbers[4] = "| 5 ";
	displayNumbers[5] = "| 6 ";
	displayNumbers[6] = "| 7 ";
	displayNumbers[7] = "| 8 ";
	displayNumbers[8] = "| 9 ";
	displayNumbers[9] = "|10 ";
	displayNumbers[10] = "| J ";
	displayNumbers[11] = "| Q ";
	displayNumbers[12] = "| K ";
	if (showDealer == false) {
		for (int i = playerI; i > 0; i--) {
			cout << " ____  ";
		}
		cout << "\n";
		for (int i = playerI; i > 0; i--) {
			cout << "|    | ";
		}
		cout << "\n";
		for (int i = playerI; i > 0; i--) {
			cout << displayNumbers[playerDeck[i].number];
			cout << displaySuits[playerDeck[i].suit];
		}
		cout << "\n";
		for (int i = playerI; i > 0; i--) {
			cout << "|____| ";
		}
	}
}