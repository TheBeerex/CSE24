// Author: beerex
// Lab 6 ArrayList

#ifndef ArrayList_H
#define ArrayList_H

#include <iostream>

struct ArrayList{
	int count;
	int capacity;
	int* data;

	ArrayList(){
		count = 0;
		capacity = 1;
		data = new int[capacity];
	}

	// Appends new item to the ArrayList, if the array needs to grow, it will call increase_capacity() to double its size
	void append(int x){
		if(count++ >= capacity){
			increase_capacity();
		}
		data[count] = x;
		count++;
	}

	//Doubles the capacity (size) of the ArrayList
	void increase_capacity(){
		//Make temp newData pointer with double capacity
		capacity = capacity * 2;
		int* newData = new int[capacity]; 

		//Copy data to newData
		for (int i = 0; i < count; i++){
			newData[i] = data[i];
		}
		// Make a temp pointer to the oldData
		int* oldData = data;
		// Copy newData to data and release oldData
		data = newData;
		delete[] oldData;
	}

	int length(){
		return count;
	}

	int cap(){
		return capacity;
	}

	//Destructor
	~ArrayList(){
		delete[] data;
	}

	// Utility function to get data[i]
	int& operator[](int i){
		return data[i];
	}

};

// Utility function to cout array
std::ostream& operator<<(std::ostream& os, ArrayList& arr){
	os << "[";
	for (int i = 0; i < arr.count; i++){
		os << arr[i];
		if (i < arr.count-1){
			os << ", ";
		}
	}
	os << "]";
	return os;
}


#endif