#include "Deck.h"
#include <iostream>
using namespace std;
Deck::Deck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Deck::deck[i][j] = 1;
		}
	}
}
string Deck::newCard() {
	int suit = rand() % 4;
	int num = rand() % 13;

}