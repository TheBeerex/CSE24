// Author: beerex
// Quadratic Equation Plotter

#include <iostream>

using namespace std;

int main() {
	float a;
	float b;
	float c;

	cout << "Enter a value for a.";
	cin >> a;
	if(a != 0){
		cout << "Enter a value for b.";
		cin >> b;
		cout << "Enter a value for c.";
		cin >> c;

		// loop over [-1, 1] @ increments of 0.1
		for(float i = -1.0; i < 1.1; i += 0.1){
			float y = a*(i*i) + b*i + c;
			cout << "(" << i << ", " << y << ")" << endl;
		}
	}
	else{
		cout << "invalid input for a (cannot be zero)" << endl;
	}
	

	return 0;
}
