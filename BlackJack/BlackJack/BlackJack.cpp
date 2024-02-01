#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{	
	bool gameplay = true;
	string command;
	Deck deck1 = Deck::Deck();
	int gamestatus = deck1.GameStatus(false,false);
	deck1.shuffle();
	while (gameplay = true) {
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
			gameplay = false;
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
			gameplay = false;
		}
		
	}
}