// Author: beerex
// Slope calculator

#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    float x1,y1,x2,y2;
 
    // Read the inputs from the user
    cout << "Enter x1: ";
    cin >> x1;

	cout << "Enter y1: ";
    cin >> y1;

	cout << "Enter x2: ";
    cin >> x2;

	cout << "Enter y2: ";
    cin >> y2;
 
    // Calculate the slope
    float slope = (y2 - y1)/(x2 - x1);
 
    // Output the result
    cout << "The slope of the line given is " << slope << endl;
 
    return 0;
}