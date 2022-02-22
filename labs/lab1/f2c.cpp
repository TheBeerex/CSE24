// Author: beerex
// Fahrenheit to Celsius calculator

#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    float tempIn;
 
    // Read the inputs from the user
    cout << "Enter a temperature in Fahrenheit: ";
    cin >> tempIn;
 
    // Calculate the temperature
    float tempOut = ((tempIn-32)*5/9);
 
    // Output the result
    cout << tempIn << " degrees Fahrenheit is equal to " << tempOut << " degrees Celsius" << endl;
 
    return 0;
}