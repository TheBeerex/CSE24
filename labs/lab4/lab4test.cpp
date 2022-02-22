#include <igloo/igloo.h>
#include "lab4.h"

using namespace igloo;

bool compare(int one[], int size1, int two[], int size2){
	if (size1 != size2){
		return false;
	}
	for (int i = 0; i < size1; i++){
		if (one[i] != two[i]){
			return false;
		}
	}
	return true;
}

Context(FindMaxTest){
	Spec(SetOne){
		int arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;
		Assert::That(find_max(arrOne, sizeOne), Equals(9));
	}

	Spec(SetTwo){
		int arrTwo[6] = {-4, -6, 99, 13, 2, 5};
		int sizeTwo = 6;
		Assert::That(find_max(arrTwo, sizeTwo), Equals(99));
	}
	
	Spec(SetThree){
		int arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;
		Assert::That(find_max(arrThree, sizeThree), Equals(104));
	}

	Spec(SetFour){
		int arrFour[4] = {-13, -15, -2, -21};
		int sizeFour = 4;
		Assert::That(find_max(arrFour, sizeFour), Equals(-2));
	}
};

Context(FindMaxPosTest){
	
	Spec(SetOne){
		int arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;
		Assert::That(find_max_pos(arrOne, sizeOne), Equals(9));
	}

	Spec(SetTwo){
		int arrTwo[6] = {-4, -6, 99, 13, 2, 5};
		int sizeTwo = 6;
		Assert::That(find_max_pos(arrTwo, sizeTwo), Equals(2));
	}
	
	Spec(SetThree){
		int arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;
		Assert::That(find_max_pos(arrThree, sizeThree), Equals(2));
	}

	Spec(SetFour){
		int arrFour[4] = {-13, -15, -2, -21};
		int sizeFour = 4;
		Assert::That(find_max_pos(arrFour, sizeFour), Equals(2));
	}
};

Context(SearchTest){
	
	Spec(SetOne){
		int arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;
		Assert::That(search(5, arrOne, sizeOne), Equals(5));
	}
	
	Spec(SetTwo){
		int arrTwo[6] = {-4, -6, 99, 13, 2, 5};
		int sizeTwo = 6;
		Assert::That(search(-6, arrTwo, sizeTwo), Equals(1));
	}

	Spec(SetThree){
		int arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;
		Assert::That(search(0, arrThree, sizeThree), Equals(1));
	}
	
	Spec(SetFour){
		int arrFour[4] = {-13, -15, -2, -21};
		int sizeFour = 4;	
		Assert::That(search(0, arrFour, sizeFour), Equals(-1));
	}
};

Context(RunningSumTest){
	
	Spec(SetOne){
		int arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;

		running_sum(arrOne, sizeOne);

		int expectedOne[10] = {0,1,3,6,10,15,21,28,36,45};
		Assert::That(compare(arrOne, sizeOne, expectedOne, sizeOne), IsTrue());
	}
	
	Spec(SetTwo){
		int arrTwo[6] = {-4, -6, 99, 13, 2, 5};
		int sizeTwo = 6;

		running_sum(arrTwo, sizeTwo);

		int expectedTwo[6] = {-4,-10,89,102,104,109};
		Assert::That(compare(arrTwo, sizeTwo, expectedTwo, sizeTwo), IsTrue());
	}
	
	Spec(SetThree){
		int arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;

		running_sum(arrThree, sizeThree);

		int expectedThree[3] = {-104,-104,0};
		Assert::That(compare(arrThree, sizeThree, expectedThree, sizeThree), IsTrue());
	}

	Spec(SetFour){
		int arrFour[4] = {-13, -15, -2, -21};
		int sizeFour = 4;

		running_sum(arrFour, sizeFour);

		int expectedFour[4] = {-13,-28,-30,-51};
		Assert::That(compare(arrFour, sizeFour, expectedFour, sizeFour), IsTrue());
	}
};

Context(TrimmedAverageTest){
	Spec(SetOne){
		float arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;
		Assert::That(trimmed_average(arrOne, sizeOne), Equals(4.5));
	}
	
	Spec(SetTwo){
		float arrTwo[6] = {-4, -6, 99, 13, 2, 5};
		int sizeTwo = 6;
		Assert::That(trimmed_average(arrTwo, sizeTwo), Equals(4));
	}

	Spec(SetThree){
		float arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;
		Assert::That(trimmed_average(arrThree, sizeThree), Equals(0));
	}
	
	Spec(SetFour){
		float arrFour[4] = {-13, -15, -2, -21};
		int sizeFour = 4;	
		Assert::That(trimmed_average(arrFour, sizeFour), Equals(-14));
	}
};

Context(SumUniqueTest){
	Spec(SetOne){
		int arrOne[10] = {0,1,2,3,4,5,6,7,8,9};
		int sizeOne = 10;
		Assert::That(sum_unique(arrOne, sizeOne), Equals(45));
	}
	Spec(SetTwo){
		int arrTwo[11] = {-4,-6,-4,99,-6,13,-99,-99,2,5,5};
		int sizeTwo = 11;
		Assert::That(sum_unique(arrTwo, sizeTwo), Equals(10));
	}
	Spec(SetThree){
		int arrThree[3] = {-104, 0, 104};
		int sizeThree = 3;
		Assert::That(sum_unique(arrThree, sizeThree), Equals(0));
	}

	Spec(SetFour){
		int arrFour[4] = {-13, -4, -13, -10};
		int sizeFour = 4;	
		Assert::That(sum_unique(arrFour, sizeFour), Equals(-27));
	}
};

Context(AutologicalTest){
	Spec(SetOne){
		int arrOne[5] = {7,9,5,2,3};
		int sizeOne = 5;
		Assert::That(autological(arrOne, sizeOne), Equals(-1));
	}
	Spec(SetTwo){
		int arrTwo[6] = {2,7,9,1,2,3};
		int sizeTwo = 6;
		Assert::That(autological(arrTwo, sizeTwo), Equals(2));
	}
	Spec(SetThree){
		int arrThree[4] = {7,9,1,3};
		int sizeThree = 4;
		Assert::That(autological(arrThree, sizeThree), Equals(1));
	}
	Spec(SetFour){
		int arrFour[4] = {4,4,4,4};
		int sizeFour = 4;
		Assert::That(autological(arrFour, sizeFour), Equals(4));
	}
};

int main(){
	return TestRunner::RunAllTests();
}







