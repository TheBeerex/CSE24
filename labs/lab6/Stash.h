// Author: beerex
// Lab 6 Stash

#ifndef STASH_H
#define STASH_H

#include <iostream>
#include <ostream>
#include <string>

struct Stash{
	unsigned char** data;
	unsigned int* type; // 0 is a char, 1 is an int, 2 is a string, 3 is a Stash
	int count;
	int capacity;

	Stash(){
		count = 0;
		capacity = 1;
		data = new unsigned char*[capacity];
		type = new unsigned int[capacity];
	}

	void inflate(){
		capacity = capacity * 2;
		unsigned char** newData = new unsigned char*[capacity]; 
		unsigned int* newType = new unsigned int[capacity]; 

		for (int i = 0; i < count; i++){
			newData[i] = data[i];
			newType[i] = type[i];
		}
		unsigned char** oldData = data;
		unsigned int* oldType = type;

		data = newData;
		type = newType;
		delete[] oldData;
		delete[] oldType;
	}

	void append(int x){
		if(count+1 >= capacity){
			inflate();
		}
		int* someInt = new int(x);
		data[count] = (unsigned char*) someInt;
		type[count] = 0;
		count++;
	}

	void append(char x){
		if(count+1 >= capacity){
			inflate();
		}
		char* someChar = new char(x);
		data[count] = (unsigned char*) someChar;
		type[count] = 1;
		count++;
	}

	void append(std::string x){
		if(count+1 >= capacity){
			inflate();
		}
		std::string* someString = new std::string(x);
		data[count] = (unsigned char*) someString;
		type[count] = 2;
		count++;
	}

	void append(const Stash& s){
		if(count+1 >= capacity){
			inflate();
		}
		data[count] = (unsigned char*) &s;
		type[count] = 3;
		count++;
	}

	int length(){
		return count;
	}

	int cap(){
		return capacity;
	}

};

// Overload << so we can cout (print out) a stash
std::ostream& operator<<(std::ostream& os, const Stash& s){
	os << "[";
	for (int i = 0; i < s.count; i++){
		if(s.type[i] == 0){
			int* temp = (int*) s.data[i];
			os << *temp;
		}else if(s.type[i] == 1){
			char* temp = (char*) s.data[i];
			os << "'" << *temp << "'";
		}else if(s.type[i] == 2){
			std::string* temp = (std::string*) s.data[i];
			os << "\"" << *temp << "\"";
		}else if(s.type[i] == 3){
			Stash* temp = (Stash*) s.data[i];
			os << *temp;
		}
		if (i < s.count-1){
			os << ", ";
		}
	}
	os << "]";
	return os;
}


#endif