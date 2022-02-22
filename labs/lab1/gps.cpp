// Author: beerex
// GPS Turn Determiner

#include <iostream>
#include <cmath>

using namespace std;

// Not all point combinations seem to work. One in particular is P1(1,1), P2(2,2), P3(2,1)

int main() { 
	try	{
		// Get points for line segments
		float x1,y1,x2,y2,x3,y3,cp;
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

		// Translate the segments such that P2=(0,0), and consider them vectors
		x1 = x1 - x2;
		y1 = y1 - y2;
		x3 = x3 - x2;
		y3 = y3 - y2;

		// Find and crossproduct of vectors (x1,y1) and (x3,y3)
		cp = (x1 * y3) - (x3 * y1);

		// Determine the turn (cp>0: right, cp<0: left, cp=0: straight)
		if (cp == 0){
			cout << "Continue straight." << endl;
		}else if(cp > 0){
			cout << "Make a right turn ahead." << endl;
		}else{
			cout << "Make a left turn ahead." << endl;
		}
	} catch (int e) {
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}
	return 0;
}