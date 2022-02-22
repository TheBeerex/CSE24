// Author: beerex
// Celsius to Fahrenheit calculator

#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
    float tempIn;
 
    // Read the inputs from the user
    cout << "Enter a temperature in Celsius: ";
    cin >> tempIn;
 
    // Calculate the temperature
    float tempOut = ( (tempIn*9/5) + 32);
 
    // Output the result
    cout << tempIn << " degrees Celsius is equal to " << tempOut << " degrees Fahrenheit" << endl;
 
    return 0;
}