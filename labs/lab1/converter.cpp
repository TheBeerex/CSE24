// Author: beerex
// Better Unit Converter

#include <iostream>
#include <cmath>

using namespace std;

int main() { 
	// Select units to convert
	int units;
	cout << "Units to convert: " << endl << "  1. Temperature" << endl << "  2. Distance" << endl << "  3. Weight" << endl << "Enter Choice: ";
	cin >> units;
	int option;
	switch(units){
		case 1 :
			// Select which direction to convert
			cout << "Temperature Options: " << endl << "  1. C -> F" << endl << "  2. F -> C" << endl << "Enter Choice: ";
			cin >> option;
			float tempIn;
			float tempOut;
			switch(option){
				case 1 : // Take input and convert C->F
					cout << "Enter a temperature in Celsius: ";
					cin >> tempIn;
					tempOut = ( (tempIn*9/5) + 32);
					cout << tempIn << " degrees Celsius is equal to " << tempOut << " degrees Fahrenheit" << endl;
					break;
				case 2 : // Take input and convert F->C
					cout << "Enter a temperature in Fahrenheit: ";
					cin >> tempIn;
					tempOut = ((tempIn-32)*5/9);
					cout << tempIn << " degrees Fahrenheit is equal to " << tempOut << " degrees Celsius" << endl;
					break;
				default :
					cout << "Invalid input" << endl;
					break;
			}
			break;
		case 2 :
			// Select which direction to convert
			cout << "Distance Options: " << endl << "  1. FT -> M" << endl << "  2. M -> FT" << endl << "Enter Choice: ";
			cin >> option;
			float distIn;
			float distOut;
			switch(option){
				case 1 : // Take input and convert FT->M
					cout << "Enter a distance of feet: ";
					cin >> distIn;
					distOut = (distIn/3.28084);
					cout << distIn << " feet is equal to " << distOut << " meter(s)" << endl;
					break;
				case 2 : // Take input and convert M->FT
					cout << "Enter a distance of meters: ";
					cin >> distIn;
					distOut = (distIn*3.28084);
					cout << distIn << " meter(s) is equal to " << distOut << " feet" << endl;
					break;
				default :
					cout << "Invalid input" << endl;
					break;
			}
			break;
		case 3 :
			// Select which direction to convert
			cout << "Weight Options: " << endl << "  1. KG -> LBS" << endl << "  2. LBS -> KG" << endl << "Enter Choice: ";
			cin >> option;
			float weightIn;
			float weightOut;
			switch(option){
				case 1 : // Take input and convert KG->LBS
					cout << "Enter a weight of kilograms: ";
					cin >> weightIn;
					weightOut = (weightIn*2.20462);
					cout << weightIn << " kilogram(s) is equal to " << weightOut << " pounds(s)" << endl;
					break;
				case 2 : // Take input and convert LBS->KG
					cout << "Enter a weight of pounds: ";
					cin >> weightIn;
					weightOut = (weightIn/2.20462);
					cout << weightIn << " pound(s) is equal to " << weightOut << " kilogram(s)" << endl;
					break;
				default :
					cout << "Invalid input" << endl;
					break;
			}
			break;
		default : 
			cout << "Invalid input" << endl;
			break;
	}
	return 0;
}