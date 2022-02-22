// Author: beerex
// Calendar

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int daysinmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int month;
	int year;
	cout << "What is the year (>= 2000)?";
	if(cin >> year){
		cout << "What is the month (1-12)?";
		if(cin >> month){
			int days = 0;
			for(int i=2000; i <= year-1; i++){
				bool leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
				if(leap){
					days+=366;
				}
				else{
					days+=365;
				}
			}
			for(int j=1; j <= month-1; j++){
				bool leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
				if(leap && (j == 2)){
					days += 29;
				}
				else{
					days += daysinmonth[j-1];
				}
			}
			int dayoftheweek = 6 - (days % 7);
			cout << days << "    " << dayoftheweek << endl;

			// print the formatted calendar month
			// !!!! Modify below code to work as a calendar !!!!

			//how many days are in the given month?
			int thismonth;
			bool leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
			if(leap && (month == 2)){
				thismonth = 29;
			}
			else{
				thismonth = daysinmonth[month-1];
			}

			//print first three rows
			cout << month << "/" << year << endl;
			cout << " S  M  T  W  R  F  S" << endl;
			cout << "--------------------" << endl;
			
			// print the weeks
			for (int k = 1; k <= 35; k++){
				if(k <= dayoftheweek){
					cout << "   ";
				}
				else{
					if( (k - dayoftheweek) <= thismonth ){
						if(k < 10+dayoftheweek){
							cout << " ";
						}
						cout << k - dayoftheweek << " ";
					} 
					else{
						cout << "   ";
					}
					
				}
				if (k % 7 == 0){
					cout << endl;
				}
			}
		}
	}
	else{
		cout << "Invalid input.";
	}
/*
//print the calendar month. Ex:
2/2019
 S  M  T  W  T  F  S 
---------------------
                1  2 
 3  4  5  6  7  8  9 
10 11 12 13 14 15 16 
17 18 19 20 21 22 23 
24 25 26 27 28       
*/
	return 0;
}
