// Author: beerex
// Drawing ASCII-Rectangle s

#include <iostream>

using namespace std;

int main() {
	int inheight;
	int inlength;

	cout << "Input a length (positive, nonzero integer).";
	cin >> inlength;
	
	if((inlength > 0)){ //verify length
		cout << "Input a height (positive, nonzero integer).";
		cin >> inheight;

		if(inheight > 0){
			// top border
			for(int i = inlength; i > 0; i--){
				cout << "* ";
			}
			cout << endl;
			// side borders
			int sideborders = inheight - 2;
			int arealength = inlength - 2;
			for(int i = sideborders; i > 0; i--){
				cout << "* ";
				for(int j = arealength; j > 0; j--){		
					cout << "  ";
				}
				cout << "*" << endl;
			}
			// bottom border
			for(int i = inlength; i > 0; i--){
				cout << "* ";
			}
		}
		else{
			cout << "invalid number" << endl;
		}
	}
	else{
		cout << "invalid number" << endl;
	}
	return 0;
}
