// Author: beerex
// Drawing ASCII-Diamonds

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int sidelength;
	cout << "Enter an positive, nonzero integer side length.";
	cin >> sidelength;
	if( (sidelength > 0) ){ // verify that sidelength is nonzero & positive
		for(int i = sidelength-1; abs(i) < sidelength; i--){ // iterate over the number lines needed: abs(i) so that it decreases to from (sidelength-1) to 0 then back up to (sidelength-1), effectively getting us the necessary (sidelength*2-1) lines for the diamond
			for(int j = abs(i); j > 0; j--){ // print the number of necessary spaces before our first *
				cout << "  ";
			}
			cout << "* ";
			if(abs(i) != sidelength-1){ // logic for printing the space before the second *
				cout << "  ";
				int change = (sidelength-1)-abs(i);
				if(change > 1){
					for(int k = (change*2 - 2); k > 0; k--){ // print the number of spaces before the second *
						cout << "  ";
					}
				}
				cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}

/* 					sidelength = 5
        * 			FIRST row is (sidelength-1)*2 spaces then one "* "
      *   * 		SECOND row is (sidelength-2)*2 spaces, then one "* ", two spaces, and one "* "
    *       *		THIRD row is (sidelength-3)*2 spaces, then one "* ", six spaces, and one "* "
  *           * 	FOURTH row (sidelength-4)*2 spaces, then one "* ", ten spaces, and one "* "
*               * 	FIFTH row is one "* ", then 14 spaces, and one "* "
  *           * 	then we go backwards
    *       * 		
      *   * 		
        * 			
*/
