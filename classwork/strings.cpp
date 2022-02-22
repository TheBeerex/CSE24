// Author: beerex
// Strings - in class commit

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string test = "This sentence is grammatically correct.";

	for(int i=0; i < test.size(); i++){
		if(test[i] == 'o'){
			test[i] = '0';
		}
		if(test[i] == 's'){
			test[i] = '$';
		}
	}

	cout << test << endl;

	return 0;
}
