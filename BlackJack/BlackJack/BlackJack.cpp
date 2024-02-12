#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{
	string command;
	bool menu = true;
	bool blackjackGameplay = false;
	bool solitaireGameplay = false;
	while (menu == true) {
		system("cls");
		cout << "s for Solitaire  b for Blackjack / 21" << "\n\n" ": ";
		cin >> command;
		if (command == "s") {
			system("cls");
			menu = false;
			solitaireGameplay = true;
		}
		if (command == "b") {
			system("cls");
			menu = false;
			blackjackGameplay = true;
		}
	}
	Deck deck1 = Deck::Deck();
	int gamestatus = deck1.GameStatus(false,false);
	deck1.shuffle();
	if (blackjackGameplay == true) {
		while (blackjackGameplay = true) {
			cout << "\n" << "\n" << " ______________    ______________________________    ____________________________________" << "\n";
			cout << "|              |  |                              |  |                                    |" << "\n";
			cout << "|Type p to Pull|  |Type 1 or 11 to swap Ace Cards|  |Type x to Call the game and count up|" << "\n";
			cout << "|______________|  |______________________________|  |____________________________________|" << "\n" << "\n";
			cout << ": ";
			cin >> command;
			if (command == "p") {
				deck1.pull(true);
				deck1.pull(false);
				deck1.Display(false, false);
				gamestatus = deck1.GameStatus(false, false);
			}
			if (command == "x") {
				gamestatus = deck1.GameStatus(true, false);
				cout << "\n";
				deck1.Display(true, true);
				gamestatus = deck1.GameStatus(true, false);
				blackjackGameplay = false;
			}
			if (command == "1") {
				deck1.SwapAceVal(true, true, true);
				deck1.Display(false, true);
				gamestatus = deck1.GameStatus(false, false);

			}
			if (command == "11") {
				deck1.SwapAceVal(true, false, true);
				deck1.Display(false, true);
				gamestatus = deck1.GameStatus(false, false);
			}
			if (gamestatus == 4) {
				deck1.SwapAceVal(true, true, false);
				deck1.Display(false, true);
				gamestatus = deck1.GameStatus(false, false);

			}
			if (gamestatus == 5) {
				gamestatus = deck1.GameStatus(false, true);

			}
			if (gamestatus > 5) {
				cout << "\n";
				deck1.Display(true, true);
				gamestatus = deck1.GameStatus(false, true);
				blackjackGameplay = false;
			}

		}
	}
	if (solitaireGameplay == true) {
		int commandRow;
		int commandCollumn;
		int commandMove;
		deck1.DisplaySolitaire(0);
		while (solitaireGameplay == true) {
			cout << "   Row: ";
			cin >> commandRow;
			deck1.DisplaySolitaire(commandRow);
			cout << "   Place from deck or Move from selected: ";
			cin >> command;
			if (command == "p") {
				deck1.checkPlaceable(true, 0, 0);
				deck1.placeCard(true, commandRow - 1);
				deck1.DisplaySolitaire(0);
			}
			if (command == "m") {
				deck1.DisplaySolitaire(commandRow);
				cout << "   How many to move: ";
				cin >> commandCollumn;
				deck1.DisplaySolitaire(commandRow);
				cout << "   Which Row: ";
				cin >> commandMove;
				deck1.checkPlaceable(false, commandRow - 1, commandCollumn);
				deck1.placeCard(false, commandMove - 1);
				deck1.DisplaySolitaire(0);

			}
		}
	}
}
