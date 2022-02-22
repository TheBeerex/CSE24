// Author: beerex
// Find and print the position of the character 'x' inside the string, -1 if it does not appear

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int pos = -1;
	string userin;
	cin >> userin;

	for(int i=0; i < userin.size(); i++){
		cout << userin[i] << endl;
		if(userin[i] == 'x'){
			pos = i;
			break;
		}
	}
	cout << pos << endl;

	return 0;
}
