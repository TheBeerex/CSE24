// Author: beerex
// 

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

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

void running_sum(int arr[], int size){
	for(int i = 1; i < size; i++){
		arr[i] = arr[i] + arr[i-1];
	}
}

void random_fill(int arr[], int size, int min, int max){
	int variance = max - min + 1;
	for(int i = 0; i < size; i++){
		arr[i] = rand() % variance + min;
	}
}

int main() {
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int size = 10;
	int min = 1;
	int max = 99;

	running_sum(arr, size);
	
	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	return 0;
}
