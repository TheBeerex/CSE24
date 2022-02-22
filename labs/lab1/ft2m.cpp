// Author: beerex
// Feet to meter calculator

#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    float distIn;
 
    // Read the inputs from the user
    cout << "Enter a distance of feet: ";
    cin >> distIn;
 
    // Calculate the distance
    float distOut = (distIn/3.28084);
 
    // Output the result
    cout << distIn << " feet is equal to " << distOut << " meter(s)" << endl;
 
    return 0;
}