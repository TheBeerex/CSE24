// Author: beerex
// 

#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cmath>
#include <random>

int find_max(int arr[], int size) {
	int max = arr[0];
	for(int i = 0; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int find_max_pos(int arr[], int size){
	int max = arr[0];
	int maxpos = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
			maxpos = i;
		}
	}
	return maxpos;
}

int search(int key, int arr[], int size){
	for(int i = 0; i < size; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

void running_sum(int arr[], int size){
	for(int i = 1; i < size; i++){
		arr[i] = arr[i] + arr[i-1];
	}
}

float trimmed_average(float values[], int size){
	if(size < 3){ //Does not work properly if size < 3, so we return -1 to show a failure.
		return -1;
	}
	//Find both min and max positions
	float max = values[0];
	int maxpos = 0;
	float min = values[0];
	int minpos = 0;
	for(int i = 0; i < size; i++){
		if(values[i] > max){
			max = values[i];
			maxpos = i;
		}
		if(values[i] < min){
			min = values[i];
			minpos = i;
		}
	}
	//Find the average excluding the min and max
	float total = 0;
	for(int i = 0; i < size; i++){
		if( (i != maxpos) && (i != minpos) ){
			total += values[i];
		}
	}
	return ( total / (size - 2) );
}

void random_fill(int arr[], int size, int min, int max){
	int variance = max - min + 1;
	for(int i = 0; i < size; i++){
		arr[i] = rand() % variance + min;
	}
}

int sum_unique(int arr[], int size){
	int unique[size];
	unique[0] = arr[0];
	int unisize = 1;
	int sum = arr[0];
	bool found;
	for(int i = 1; i < size; i++){
		found = false;
		for(int j=0; j < unisize; j++){
			if(arr[i] == unique[j]){
				found = true;
				break;
			}
		}
		if(!found){
			sum += arr[i];
			unique[unisize] = arr[i];
			unisize++;
		}
	}
	return sum;
}

// TODO Autological Elements
int autological(int arr[], int size){
	// Initialize 2D array with size rows and 2 columns. 
	// Column 1 being the unique elements of arr[].
	// Column 2 being the count of correstponding elements.
	int uniques[size][2];
	int unisize = 1;
	uniques[0][0] = arr[0];
	for(int j = 0; j < size; j++){ //Counts of all elements start at 0
		uniques[j][1] = 0;
	}
	for(int i = 0; i < size; i++){ //Count of element [0][0] is the count of arr[0]
		if(arr[i] == uniques[0][0]){
			uniques[0][1] = uniques[0][1] + 1;
		}
	}
	// Find other unique elements and their counts
	bool found;
	for(int k = 1; k < size; k++){
		found = false;
		for(int p = 0; p < unisize; p++){
			if(arr[k] == uniques[p][0]){
				found = true;
				break;
			}
		}
		if(!found){
			uniques[unisize][0] = arr[k];
			for(int u = k; u < size; u++){
				if(arr[k]==arr[u]){
					uniques[unisize][1] = uniques[unisize][1] + 1;
				}
			}
			unisize++;
		}
	}
	// Find largest autological element
	int largest = -1;
	for(int t = 0; t < unisize; t++){
		if(uniques[t][0]==uniques[t][1]){
			if(uniques[t][0] > largest){
				largest = uniques[t][0];
			}
		}
	}
	return largest;
}





#endif