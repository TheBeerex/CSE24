#include <iostream>
#include "classwork.h"

using namespace std;

int main(){

	const int size = 5;

	int arr[size] = {1,2,3,4,5};

	int total = sum(arr, size);

	cout << total << endl;

	return 0;
}