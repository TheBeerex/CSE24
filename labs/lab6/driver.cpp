// Author: beerex
// Lab 6 Driver

#include <iostream>
#include "Stash.h"
 
using namespace std;
 
int main(){

	Stash t;

	t.append(99);
	t.append('X');
	t.append(73);
	t.append("Hello");

	cout << t << endl;
	cout << "Length: " << t.length() << endl;
	cout << "Capacity: " << t.cap() << endl;

	Stash s;

	s.append(5);
	s.append(7);
	s.append('A');
	s.append(1);
	s.append(t);
	s.append(9);
	s.append("World");

	cout << s << endl;
	cout << "Length: " << s.length() << endl;
	cout << "Capacity: " << s.cap() << endl;

	return 0;
}