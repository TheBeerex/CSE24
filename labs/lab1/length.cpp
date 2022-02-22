// Author: beerex
// Length of a segment calculator

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
 
    // Calculate the length
    float legnth = sqrt( (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2) );
 
    // Output the result
    cout << "The length of the segment given is " << legnth << endl;
 
    return 0;
}