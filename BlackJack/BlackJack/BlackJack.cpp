#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{	
	bool won = false;
	string command;
	Deck deck1 = Deck::Deck();
	while (won == false) {
		cout << "\n" << "?" << "\n";
		cin >> command;
		if (command == "p") {
			deck1.pull(true);
			deck1.Display(false);
		}
	}
}