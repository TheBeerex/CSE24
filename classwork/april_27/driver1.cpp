#include <iostream>

using namespace std;

int* merge(int* first, int* second, int size1, int size2){
	int p1 = 0;
	int p2 = 0;
	int* result = new int[(size1+size2)];

	for(int i = 0; i < (size1+size2); i++){
		if(p1 >= size1){
			result[i] = second[p2];
			p2++;
		}else if(p2 >= size2){
			result[i] = first[p1];
		}else{
			if(first[p1] <= second[p2]){
				result[i] = first[p1];
				p1++;
			}else{
				result[i] = second[p2];
				p2++;
			}
		}
	}
	return result;
}

int main(){
	const int oddSize = 5;
	const int evenSize = 5;
	int odds[oddSize] = {1, 3, 5, 7, 9};
	int evens[evenSize] = {2, 4, 6, 8, 10};

	int* result = merge(odds, evens, oddSize, evenSize);

	for (int i = 0; i < oddSize + evenSize; i++){
		cout << result[i];
		if (i < oddSize + evenSize - 1){
			cout << ", ";
		}
	}
	cout << endl;

	delete[] result;

	return 0;
}