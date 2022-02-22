// Author: beerex

#include <iostream>
#include <string>
#include <random>

using namespace std;

/*

I play a lot of tabletop games so I chose to make a Dice struct.
It will:
	- have variables describing: 1) its number of sides, 2) its color, 3) its style/material (i.e. plastic, liquid core, metal, etc.), and 4) whether or not it is in "dice jail"
	- have a function to be rolled, however it will not roll a dice that is "jailed" (return -1)
	- a die cannot have less than 2 sides

*/

struct Dice{ 
	int sides;
	string color;
	string style;
	bool inJail;

	Dice(){
		//Assume it's a basic d6.
		sides = 6;
		color = "white";
		style = "plastic";
		inJail = false;
	}

	Dice(int s, string c, string l, bool j){
		if(s >= 2){
			sides = s;
			color = c;
			style = l;
			inJail = j;
		}else{
			throw logic_error("Cannot have die of size < 2");
		}
	}

	int roll(){
		if(inJail){
			return -1;
		}else{
			random_device rd;
			mt19937 rng(rd());

			uniform_int_distribution<int> uni(1, sides);
			return uni(rng);
		}
	}
};

ostream& operator<<(ostream& os, Dice& dice){
	os << dice.color << ", " << dice.style << " d" << dice.sides;
	if(dice.inJail){
		os << " is in Jail";
	}
	return os;
}

int main(){
	Dice* goodDie = new Dice();
	Dice* badDie = new Dice(20, "orange", "plastic", true);

	cout << *goodDie << "    " << goodDie << endl;
	cout << goodDie->roll() << endl;
	cout << *badDie << "    " << badDie << endl;
	cout << badDie->roll() << endl;

	delete goodDie;
	delete badDie;

	return 0;
}







