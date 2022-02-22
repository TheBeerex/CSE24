// Author: beerex

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <time.h>

struct Card{
	std::string index;
	std::string suit;

	Card(){
		index = "";
		suit = "";
	}

	Card(std::string i, std::string s){
		index = i;
		suit = s;
	}

};

struct Deck{
	Card theDeck[52];

	Deck(){
		theDeck[0] = Card("A","Clubs");
		theDeck[1] = Card("2","Clubs");
		theDeck[2] = Card("3","Clubs");
		theDeck[3] = Card("4","Clubs");
		theDeck[4] = Card("5","Clubs");
		theDeck[5] = Card("6","Clubs");
		theDeck[6] = Card("7","Clubs");
		theDeck[7] = Card("8","Clubs");
		theDeck[8] = Card("9","Clubs");
		theDeck[9] = Card("10","Clubs");
		theDeck[10] = Card("J","Clubs");
		theDeck[11] = Card("Q","Clubs");
		theDeck[12] = Card("K","Clubs");
		
		theDeck[13] = Card("A","Diamonds");
		theDeck[14] = Card("2","Diamonds");
		theDeck[15] = Card("3","Diamonds");
		theDeck[16] = Card("4","Diamonds");
		theDeck[17] = Card("5","Diamonds");
		theDeck[18] = Card("6","Diamonds");
		theDeck[19] = Card("7","Diamonds");
		theDeck[20] = Card("8","Diamonds");
		theDeck[21] = Card("9","Diamonds");
		theDeck[22] = Card("10","Diamonds");
		theDeck[23] = Card("J","Diamonds");
		theDeck[24] = Card("Q","Diamonds");
		theDeck[25] = Card("K","Diamonds");

		theDeck[26] = Card("A","Hearts");
		theDeck[27] = Card("2","Hearts");
		theDeck[28] = Card("3","Hearts");
		theDeck[29] = Card("4","Hearts");
		theDeck[30] = Card("5","Hearts");
		theDeck[31] = Card("6","Hearts");
		theDeck[32] = Card("7","Hearts");
		theDeck[33] = Card("8","Hearts");
		theDeck[34] = Card("9","Hearts");
		theDeck[35] = Card("10","Hearts");
		theDeck[36] = Card("J","Hearts");
		theDeck[37] = Card("Q","Hearts");
		theDeck[38] = Card("K","Hearts");

		theDeck[39] = Card("A","Spades");
		theDeck[40] = Card("2","Spades");
		theDeck[41] = Card("3","Spades");
		theDeck[42] = Card("4","Spades");
		theDeck[43] = Card("5","Spades");
		theDeck[44] = Card("6","Spades");
		theDeck[45] = Card("7","Spades");
		theDeck[46] = Card("8","Spades");
		theDeck[47] = Card("9","Spades");
		theDeck[48] = Card("10","Spades");
		theDeck[49] = Card("J","Spades");
		theDeck[50] = Card("Q","Spades");
		theDeck[51] = Card("K","Spades");
	}

	void revealTop(int n){
		int count = n;
		if(count > 52){
			count = 52;
		}
		for(int j=0; j < count; j++){
			std::cout << theDeck[j].index << " " << theDeck[j].suit << std::endl;
		}
	}

	void shuffle(){
		Card tempCard;

		std::random_device rd;
		std::mt19937 rng(rd());
		// Shuffle deck using a Fisher-Yates shuffle
		for(int i = 51; i > 0; i--){
			std::uniform_int_distribution<> uni(0, i);
			int j = uni(rng);

			tempCard = theDeck[i];
			theDeck[i] = theDeck[j];
			theDeck[j] = tempCard;
		}
		std::cout << "shuffled the deck" << std::endl;
	}
};







#endif