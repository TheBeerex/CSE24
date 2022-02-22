// Author: beerex
// Lab 5 BagOfMarbles Driver

#include <iostream>
#include "BagOfMarbles.h"

using namespace std;

int main(){

	const int count = 10;
	int marbles[count] = {0,1,2,3,4,5,6,7,8,9};
	
	BagOfMarbles myBag = BagOfMarbles(marbles, count);
	myBag.print();

	cout << myBag.pick() << " was found." << endl;
	myBag.print();

	cout << myBag.pick() << " was found." << endl;
	myBag.print();

	cout << myBag.pick() << " was found." << endl;
	myBag.print();

	return 0;
}