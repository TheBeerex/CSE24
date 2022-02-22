// Author: beerex
// Meter to feet calculator

#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    float distIn;
 
    // Read the inputs from the user
    cout << "Enter a distance of meters: ";
    cin >> distIn;
 
    // Calculate the distance
    float distOut = (distIn*3.28084);
 
    // Output the result
    cout << distIn << " meter(s) is equal to " << distOut << " feet" << endl;
 
    return 0;
}