#include "Deck.h"
#include <iostream>
#include "Card.h"
#include <ctime>
#include <cstdlib>
using namespace std;
//Blackjack and Solitaire
Card deck[52];
string displaySuits[4];
string displayNumbers[13];
//Blackjack
Card playerDeck[52];
Card dealerDeck[52];
static int playerI = 0;
static int playerDisplayI = -1;
static int dealerI = 0;
static int dealerDisplayI = -1;
int playerTotal = 0;
int dealerTotal = 0;
//Solitaire
Card table[7][13];
Card AcePiles[4][13];
static int deckI = 0;
bool canPlace[7] = {0, 0, 0, 0, 0, 0, 0};
bool canPlaceAce[4] = { 0, 0, 0, 0 };
int tableI[7] = { 0, 0, 0, 0, 0, 0, 0 };
int aceI[4] = {0, 0, 0, 0};
string select[12];
string selectAce[4];
int selectCollumn;
int selectCard[2];

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

void Deck::checkPlaceable(bool player, int tablex, int tabley) {
	for (int i = 0; i < 7; i++) {
		canPlace[i] = 0;
	}
	for (int x = 0; x < 7; x++) {
		for (int i = 0; i < 13; i++) {
			if (table[x][i].number != NULL) {
				if (player == true) {
					if (table[x][i].colour != deck[deckI].colour && table[x][i].number == deck[deckI].number + 1) {
						canPlace[x] = 1;
					}
					else {
						canPlace[x] = 0;
					}
					if (x < 4) {
						if (AcePiles[x][i].suit == deck[deckI].suit && AcePiles[x][i].number == deck[deckI].number - 1) {
							canPlaceAce[x] = 1;
						}
						else {
							canPlaceAce[x] = 0;
						}
					}
				}
				if (player == false) {
					selectCard[0] = tablex;
					selectCard[1] = tableI[tablex] - tabley;
					if (table[tablex][selectCard[1]].colour != table[x][i].colour && table[tablex][selectCard[1]].number == table[x][i].number - 1) {
						canPlace[x] = 1;
					}
					else {
						canPlace[x] = 0;
					}
					if (x < 4) {
						if (tabley == 1 && AcePiles[x][i].suit == table[tablex][selectCard[1]].suit && AcePiles[x][i].number == table[tablex][selectCard[1]].number - 1) {
							canPlaceAce[x] = 1;
						}
						else {
							canPlaceAce[x] = 0;
						}
					}
				}
			}
		}
		if (table[x][0].number == NULL) {
			canPlace[x] = 1;
		}
		if (x < 4) {
			if (AcePiles[x][0].number == NULL) {
				if (deck[deckI].number == 0 && player == true && tabley == 1) {
					canPlaceAce[x] = 1;
				}
				if (table[selectCard[0]][selectCard[1]].number == 0 && player == false && tabley == 1) {
					canPlaceAce[x] = 1;
				}
				
			}
		}
	}
}

void Deck::placeCard(bool player, int row) {
	if (player == true) {
		if (row > 6) {
			row = row - 7;
			if (canPlaceAce[row] == 1) {
				AcePiles[row][aceI[row]] = deck[deckI];
				aceI[row]++;
				deckI++;
				canPlace[row] = 0;
			}
		}
		else if (canPlace[row] == 1) {
			table[row][tableI[row]] = deck[deckI];
			tableI[row]++;
			deckI++;
			canPlace[row] = 0;
		}
	}
	if (player == false) {
		int cardsRemoved = 0;
		if (canPlace[row] == 1) {
			for (int i = selectCard[1]; i < tableI[selectCard[0]]; i++) {
				table[row][tableI[row]] = table[selectCard[0]][i];
				tableI[row]++;
				table[selectCard[0]][i] = table[selectCard[0]][tableI[selectCard[0]]];
				cardsRemoved++;
			}
			tableI[selectCard[0]] = tableI[selectCard[0]] - cardsRemoved;
		}
	}
}

void Deck::DisplaySolitaire(int displayRow) {
	system("cls");
	displaySuits[0] = "D| ";
	displaySuits[1] = "H| ";
	displaySuits[2] = "S| ";
	displaySuits[3] = "C| ";
	displayNumbers[0] = "|A ";
	displayNumbers[1] = "|2 ";
	displayNumbers[2] = "|3 ";
	displayNumbers[3] = "|4 ";
	displayNumbers[4] = "|5 ";
	displayNumbers[5] = "|6 ";
	displayNumbers[6] = "|7 ";
	displayNumbers[7] = "|8 ";
	displayNumbers[8] = "|9 ";
	displayNumbers[9] = "|10";
	displayNumbers[10] = "|J ";
	displayNumbers[11] = "|Q ";
	displayNumbers[12] = "|K ";
	select[0] = " <1>   <2>   <3>   <4>   <5>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[1] = " <*>   <2>   <3>   <4>   <5>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[2] = " <1>   <*>   <3>   <4>   <5>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[3] = " <1>   <2>   <*>   <4>   <5>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[4] = " <1>   <2>   <3>   <*>   <5>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[5] = " <1>   <2>   <3>   <4>   <*>   <6>   <7>      <8>       <9>     <10>     <11>";
	select[6] = " <1>   <2>   <3>   <4>   <5>   <*>   <7>      <8>       <9>     <10>     <11>";
	select[7] = " <1>   <2>   <3>   <4>   <5>   <6>   <*>      <8>       <9>     <10>     <11>";
	select[8] = " <1>   <2>   <3>   <4>   <5>   <6>   <7>      <*>       <9>     <10>     <11>";
	select[9] = " <1>   <2>   <3>   <4>   <5>   <6>   <7>      <8>       <*>     <10>     <11>";
	select[10] = " <1>   <2>   <3>   <4>   <5>   <6>   <7>      <8>       <9>     <*>      <11>";
	select[11] = " <1>   <2>   <3>   <4>   <5>   <6>   <7>      <8>       <9>     <10>     <*>";
	cout << select[displayRow];
	for (int i = 0; i < 13; i++) {
		cout << "\n";
		for (int j = 0; j < 11; j++) {
			if (j < 7) {
				if (table[j][i].number != NULL) {
					cout << displayNumbers[table[j][i].number] << displaySuits[table[j][i].suit];
				}
				else {
					cout << "      ";
				}
			}
			if (j > 6) {
				cout << " | ";
				if (AcePiles[j-7][i].number != NULL) {
					cout << displayNumbers[AcePiles[j-7][i].number] << displaySuits[AcePiles[j-7][i].suit];
				}
				else {
					cout << "      ";
				}
				if (j == 10) {
					cout << " | ";
				}
			}
		}
		cout << "\n";
		for (int j = 0; j < 11; j++) {
			if (j < 7) {
				if (table[j][i].number != NULL) {
					cout << "|___| ";
				}
				else {
					cout << "      ";

				}
			}
			if (j > 6) {
				cout << " | ";
				if (AcePiles[j-7][i].number != NULL) {
					cout << "|___| ";
				}
				else {
					cout << "      ";

				}
				if (j == 10) {
					cout << " | ";
				}
			}
		}
	}
	cout << "\n";
	cout << " ___ " << "\n";
	cout << displayNumbers[deck[deckI].number] << displaySuits[deck[deckI].suit] << "\n";
	cout << "|___| ";
}

void Deck::pull(bool player) {
	if (player == true) {
		for (int i = playerI; i >= 0; i--) {
			int j = i + 1;
			playerDeck[j] = playerDeck[i];
		}
		playerDeck[0] = deck[playerI];

		playerTotal = playerTotal + playerDeck[0].value;
		playerI++;
		dealerI++;
	}
	if (player == false) {
		for (int i = dealerI; i >= 0; i--) {
			int j = i + 1;
			dealerDeck[j] = dealerDeck[i];
		}
		dealerDeck[0] = deck[dealerI];
		dealerTotal = dealerTotal + dealerDeck[0].value;
		dealerI++;
		playerI++;
	}
	
}

void Deck::shuffle() {
	unsigned int seed = static_cast<unsigned int>(time(nullptr));
	srand(seed);
	for (int i = 0; i < 52; i++) {
		int j = rand() % 52;
		swap(deck[i], deck[j]);
	}
}

void Deck::Display(bool showDealer, bool refresh) {
	system("cls");
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

	if (showDealer == true) {
		if (refresh == false) {
			dealerDisplayI++;
		}
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << " ____  ";
		}
		cout << "\n";
		for (int i = 0; i <= dealerDisplayI; i++) {
			if (dealerDeck[i].value == 11) {
				cout << "| 11 | ";
			}
			else if (dealerDeck[i].value == 1) {
				cout << "|  1 | ";
			}
			else {
				cout << "|    | ";
			}
		}
		cout << "\n";
		for (int i = 0; i <= dealerDisplayI; i++) {
			cout << displayNumbers[dealerDeck[i].number];
			cout << displaySuits[dealerDeck[i].suit];
		}
		cout << dealerTotal;
		cout << "\n";
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << "|____| ";
		}
		cout << "\n";
	}
	if (showDealer == false) {
		if (refresh == false) {
			dealerDisplayI++;
		}
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << " ____  ";
		}
		cout << "\n";
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << "|    | ";
		}
		cout << "\n";
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << "|    | ";
		}
		cout << "\n";
		for (int i = dealerDisplayI; i >= 0; i--) {
			cout << "|____| ";
		}
		cout << "\n";
	}
	if (refresh == false) {
		playerDisplayI++;
	}
	for (int i = playerDisplayI; i >=0; i--) {
		cout << " ____  ";
	}
	cout << "\n";
	for (int i = 0; i <=playerDisplayI; i++) {
		if (playerDeck[i].value == 11) {
			cout << "| 11 | ";
		}
		else if (playerDeck[i].value == 1) {
			cout << "|  1 | ";
		}
		else {
			cout << "|    | ";
		}
	}
	cout << "\n";
	for (int i = 0; i <= playerDisplayI; i++) {
		cout << displayNumbers[playerDeck[i].number];
		cout << displaySuits[playerDeck[i].suit];
	}
	cout << playerTotal;
	cout << "\n";
	for (int i = playerDisplayI; i >=0; i--) {
		cout << "|____| ";
	}
}

bool Deck::SwapAceVal(bool player, bool toOne, bool manual) {
	if (player == true) {
		if (toOne == true) {
			for (int i = 0; i < playerI; i++) {
				if (playerDeck[i].value == 11) {
					playerDeck[i].value = 1;
					playerTotal = playerTotal - 10;
					if (manual == true) {
						cout << "Player total is now " << playerTotal << "\n";
					}
					if (manual == false) {
						cout << "\n" << "An Ace card has been switched from 11 to 1 to avoid going bust" << "\n";
					}
					return true;
				}
			}
		}
		if (toOne == false) {
			if (playerTotal > 11) {
				cout << "You cannot swap an Ace card from 1 to 11 because you will go bust :(" << "\n";
			}
			else {
				for (int i = 0; i < playerI; i++) {
					if (playerDeck[i].value == 1) {
						playerDeck[i].value = 11;
						playerTotal = playerTotal + 10;
						cout << "Player total is now " << playerTotal;

						return true;
					}
				}
			}
		}
	}
}

int Deck::getTotal(bool player) {
	if (player == true) {
		return playerTotal;
	}
	if (player == false) {
		return dealerTotal;
	}
}

int Deck::GameStatus(bool playerEnd, bool bust) {
	if (playerEnd == true) {
		if (playerTotal > dealerTotal) {
			cout << "\n" << "You Win :)";
			return 1;
		}
		else if (playerTotal == dealerTotal) {
			cout << "\n" << "You Draw :|";
			return 2;
		}
		else {
			cout << "\n" << "You Lose :(";
			return 3;
		}

	}
	if (bust == false) {
		if (playerTotal > 21) {
			bool aceInDeck = false;
			for (int i = 0; i <= playerI; i++) {
				if (playerDeck[i].value == 11) {
					return 4;
					aceInDeck = true;
				}
			}
			if (aceInDeck == false) {
				return 5;
			}
		}
	}
	if (bust == true) {
		if (playerTotal > dealerTotal) {
			cout << "\n" << "You went bust and Lost against the dealer :(";
			return 8;
		}
		else if (playerTotal == dealerTotal) {
			cout << "\n" << "You went bust and you Drew with the dealer :|";
			return 7;
		}
		else {
			cout << "\n" << "You went bust but you Beat the dealer :)";
			return 6;
		}
	}
	else {
		return 0;
	}
}