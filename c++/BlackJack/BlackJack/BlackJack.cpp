#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{
	Card card1 = Card::Card();
	Card card2 = Card::Card();
	Card card3 = Card::Card();
	Card card4 = Card::Card();
	Card card5 = Card::Card();
	card1.getCard();
	card2.getCard();
	card3.setCard(3, 10);
	card3.getCard();
	card4.getCard();
	card5.getCard();
}

//Display Variable is not updated by setCard function
//Make Display Function to go inside Card functions
//Will eventually be part of the display class that hosts the ascii and layout