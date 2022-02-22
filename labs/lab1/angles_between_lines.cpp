// Author: beerex
// Angles Between Lines

#include <iostream>
#include <cmath>

using namespace std;

// Not all point combinations seem to work. One in particular is P1(1,1), P2(2,2), P3(2,1)

int main() { 
	try	{
		// Get points for line segments
		float x1,y1,x2,y2,x3,y3;
		cout << "P1(x1,y1), P2(x2,y2), P3(x3,y3)." << endl << "Lines P1-P2, P2-P3" << endl;
		cout << "Enter x1: ";
		cin >> x1;
		cout << "Enter y1: ";
		cin >> y1;
		cout << "Enter x2: ";
		cin >> x2;
		cout << "Enter y2: ";
		cin >> y2;
		cout << "Enter x3: ";
		cin >> x3;
		cout << "Enter y3: ";
		cin >> y3;

		// Find slopes of lines P1-P2 & P2-P3
		float m1,m2;
		m1 = (y2-y1)/(x2-x1);
		m2 = (y3-y2)/(x3-x2);

		// Find and print theta
		float theta;
		theta = atan(abs((m2 - m1)/(1 + (m1*m2))));
		cout << theta << endl;

	} catch (int e) {
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	return 0;
}