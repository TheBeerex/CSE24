// Author: beerex
// Multiplication Tables

#include <iostream>

using namespace std;

int main() {
	int input;
	cout << "Input integers from 1 to 12, (end by typing a letter).";
	while (cin >> input){
		if( (input < 13) && (input > 0) ){
			for (int i = 12; i > 0; i--){
				int mult = input * i;
				cout << input << " x " << i << " = " << mult << endl;
			}
		}
		else{
			cout << "invalid number." << endl;
		}
	}
	return 0;
}
