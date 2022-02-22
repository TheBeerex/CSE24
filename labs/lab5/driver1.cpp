// Author: beerex
// Lab 5 Cards Driver

#include <iostream>
#include "Cards.h"

using namespace std;

int main(){

	Deck myCards;

	myCards.revealTop(5);

	myCards.shuffle();

	myCards.revealTop(5);

	return 0;
}