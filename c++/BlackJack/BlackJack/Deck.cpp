#include "Deck.h"
#include <iostream>
#include "Card.h"
using namespace std;
Deck::Deck() {
	int n = 0;
	Card deck[52];
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			Card card = Card::Card();
			card.setCard(i, j);
			deck[n] = { card };
			n++;
			int shownumber;
			shownumber = deck[n].number;
			cout << shownumber;
		}
	}
}