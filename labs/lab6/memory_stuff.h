// Author: beerex
// Lab 6 Memory Stuff

#ifndef MEMORY_STUFF_H
#define MEMORY_STUFF_H

#include <iostream>

void memory_contents(int x){
	unsigned char* p = (unsigned char*) &x;

	for(int i = 0; i < 4; i++){
		std::cout << (int) *(p+i) << std::endl;
	}

}

int build_integer(unsigned char first, unsigned char second, unsigned char third, unsigned char fourth){
	int output = 0;
	unsigned char* p = (unsigned char*) &output;

	*p = first;
	*(p+1) = second;
	*(p+2) = third;
	*(p+3) = fourth;

	return output;
}

struct FixedArrayList{
	int size;
	int* data;

	FixedArrayList(){
		size = 10;
		data = new int[size];
		for(int i = 0; i < size; i++){
			data[i] = 0;
		}
	}

	FixedArrayList(int x){
		size = x;
		data = new int[size];
		for(int i = 0; i < size; i++){
			data[i] = 0;
		}
	}

	void put(int x, int pos){
		if(pos >= size){
			throw std::logic_error("Index out of bounds");
		}
		data[pos] = x;
	}

	int get(int pos){
		if(pos >= size){
			throw std::logic_error("Index out of bounds");
		}
		return data[pos];
	}
};


#endif