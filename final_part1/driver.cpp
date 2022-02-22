#include <iostream>
#include <random>

using namespace std;

void fillRandomSortedUnique(int* arr, int size, int lower, int upper){
	random_device rd;
	mt19937 rng(rd());

	int bucket_size = (upper - lower + 1) / size;
	int start = lower;

	for(int i = 0; i < size; i++){
		int min = start;
		int max = start + bucket_size - 1;
		if(i == size-1){
			max = max + (upper - max);
		}

		uniform_int_distribution<int> uni(min, max);
		arr[i] = uni(rng);

		start = max + 1;
	}
}

/*
	Instead of start = max+1, we can make it equal to the integer we just generated +1, i.e. arr[i]+1, and account for the difference in the last item of the array.

	This makes the algorithm a little less predictable while keeping it in O(n).

	The flaw with logic though is that the first size-1 values will still be within a bucket_size of each other.
*/
void fillRandomSortedUniqueFixed(int* arr, int size, int lower, int upper){
	random_device rd;
	mt19937 rng(rd());

	int bucket_size = (upper - lower + 1) / size;
	int start = lower;

	for(int i = 0; i < size; i++){
		int min = start;
		int max = start + bucket_size - 1;
		if(i == size-1){
			max = max + (upper - max);
		}

		uniform_int_distribution<int> uni(min, max);
		arr[i] = uni(rng);

		start = arr[i] + 1;
	}
}

int main(){ 
	const int size = 5;
	const int low = 5;
	const int high = 101;
	
	int arr[size] = {0};
	
	fillRandomSortedUniqueFixed(arr, size, low, high);

	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
