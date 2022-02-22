// Author: beerex
// Quadratic Equation Solver

#include <iostream>
#include <cmath>

using namespace std;

int main() { 
	float a;
	float b;
	float c;

	cout << "At any point, you can type a character to stop the program.";
	cout << "Enter a value for a.";
	while(cin >> a){
		if(a != 0){
			cout << "Enter a value for b.";
			if(cin >> b){
				cout << "Enter a value for c.";
				if(cin >> c){
					// Check discriminate
					float disc = (b * b) - (4 * a * c);
					if(disc >= 0){ // find roots if disc. is not negative
						float x1 = (-1*b + (sqrt(disc)))/(2*a);
						float x2 = (-1*b - (sqrt(disc)))/(2*a);
						cout << "x1 = " << x1 << " and x2 = " << x2 << endl;
					}
					else{
						cout << "Roots are not real." << endl;
					}
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		else{
			cout << "invalid input for a (cannot be zero)" << endl;
		}
		cout << "Enter a value for a.";
	}

	return 0;
}
