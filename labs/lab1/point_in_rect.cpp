// Author: beerex
// Point in Rectangle Checker

// Note:
// Yes, I know I'm technically not following directions, this file would be equivalent
// to point_in_rect2.cpp, but I wrote this up prior to reading excersize 3 in 6.6. It 
// made the most sense to not take in all four of the corners of the rectangle since it 
// would require an added layer of validation just to make sure the user actually input
// a rectangle. It's simpler to use two points to define the rectangle instead of four. 
// My apologies for that.

#include <iostream>
#include <cmath>

using namespace std;

int main() { 
	try	{
		// Get points (rect corners and the point to be checked)
		float x1,y1,x2,y2,x,y;
		cout << "Enter x1 (x coord of the first corner of the rect): ";
		cin >> x1;
		cout << "Enter y1 (y coord of the first corner of the rect): ";
		cin >> y1;
		cout << "Enter x2 (x coord of the second corner of the rect): ";
		cin >> x2;
		cout << "Enter y2 (y coord of the second corner of the rect): ";
		cin >> y2;
		cout << "Enter x (x coord of the point to be checked): ";
		cin >> x;
		cout << "Enter y (y coord of the point to be checked): ";
		cin >> y;

		// Find lower and upper x/y bounds of the rect
		float lboundx, uboundx, lboundy, uboundy;
		if(x1 > x2){
			lboundx = x2;
			uboundx = x1;
		} else{
			lboundx = x1;
			uboundx = x2;
		}
		if(y1 > y2){
			lboundy = y2;
			uboundy = y1;
		} else{
			lboundy = y1;
			uboundy = y2;
		}

		// Check if the given point is within the rectangle
		if( (x >= lboundx) && (x <=uboundx) && (y >= lboundy) && (y <=uboundy) ) {
			cout << "The given point is in the given rectangle." << endl;
		} else{
			cout << "The given point is not in the given rectangle." << endl;
		}

	} catch (int e) {
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	return 0;
}