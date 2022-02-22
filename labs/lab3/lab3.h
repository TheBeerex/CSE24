// Author: beerex
// 

#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include <cmath>

std::string regroup(std::string s){
	std::string letters = "";
	std::string numbers = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] <= '9' && s[i] >= '0'){
			numbers += s[i];
		}
		else{
			letters += s[i];
		}
	}
	return letters + numbers;
}

int count_upper(std::string s){
	int count = 0;
	for(int i = 0; i < s.size(); i++){
		if(isupper(s[i])){
			count++;
		}
	}
	return count;
}

std::string transform_case(std::string s){
	std::string output = "";
	for(int i = 0; i < s.size(); i++){
		if(isupper(s[i])){
			output += tolower(s[i]);
		}
		else if(islower(s[i])){
			output += toupper(s[i]);
		}
		else{
			output += s[i];
		}
	}
	return output;
}

int rotation_distance( std::string a, std::string b){
	int rotr = -1;
	int rotl = -1;
	// Rotate string b until a=b. If a!=b, return -1.
	if(a != b){
		//Check right rotations.
		std::string temp = a;
		std::string temp1 = a;
		for(int j = 0; j < temp.size();j++){
			for(int i=0; i < temp.size(); i++){
				if(i==0){
					temp1[0]=temp[temp.size()-1];
				}else{
					temp1[i] = temp[i-1];
				}
			}
			if(temp1 != b){
				temp = temp1;
			}else{
				rotr = j+1;
				break;
			}
		}
		//Check left rotations.
		temp = a;
		temp1 = a;
		for(int j = 0; j < temp.size(); j++){
			for(int i=0; i < temp.size(); i++){
				if(i==temp.size()-1){
					temp1[temp.size()-1] = temp[0];
				}else{
					temp1[i] = temp[i+1];
				}
			}
			if(temp1 != b){
				temp = temp1;
			}else{
				rotl = j+1;
				break;
			}
		}
		//Check if the left or right rotations is smaller.
		if(rotr == rotl){
			return rotr;
		}else if(rotr < rotl){
			return rotr;
		}else{
			return rotl;
		}
	}else{
		return 0;
	}
}

std::string compress(std::string s){
	std::string output = "";
	char savedchar = s[0];
	int count = 1;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == savedchar){
			count++;
		}else{
			if(count > 1){
				output += savedchar + std::to_string(count);
			}else{
				output += savedchar;
			}
			savedchar = s[i];
			count = 1;
		}
		if(i == s.size()-1){
			if(count > 1){
				output += savedchar + std::to_string(count);
			}else{
				output += savedchar;
			}
		}
	}
	return output;
}

bool symmetric(std::string s){
	char symChars [14] = {'A', 'O', 'I', 'H', 'M', 'T', '8', '0', 'V', 'W', 'X', 'Y', 'U', ' '};

	std::string symPairs [26] = {"AA", "OO", "II", "HH", "MM", "TT", "88", "00", "VV", "WW", "XX", "YY", "UU", "  ", "1I", "I1", "2S", "S2", "52", "25" "3E", "E3", "9P", "P9", "JL", "LJ"};

	// Check if the given string has an even length of chars.
	bool iseven = false;
	if(s.size()%2 == 0){
		iseven = true;
	}
	
	bool sym;
	//If the string has an even length of chars.
	if(iseven){
		// Loop through and see if the halves are "symmetric."
		std::string spair = "01";
		for(int i=0; i < (s.size()/2); i++){
			sym = false;
			spair[0] = s[i];
			spair[1] = s[(s.size()-1)-i];
			for(int j=0; j < 26; j++){
				if(spair == symPairs[j]){
					sym = true;
					break;
				}
			}
			if(!sym){
				return false;
			}
		}
		return true;
	}else{//Otherwise...
		// Check if the middle char is symmetric
		char midchar = s[floor(s.size()/2)];
		bool midcheck = false;
		for(int i=0; i < 14;i++){
			if(midchar == symChars[i]){
				midcheck = true;
				break;
			}
		}
		// If midchar is symmetric 
		if(midcheck){
			// Check the symmetry of the rest of the string
			std::string spair = "01";
			for(int i=0; i < floor(s.size()/2); i++){
				sym = false;
				spair[0] = s[i];
				spair[1] = s[(s.size()-1)-i];
				for(int j=0; j < 26; j++){
					if(spair == symPairs[j]){
						sym = true;
						break;
					}
				}
				if(!sym){
					return false;
				}
			}
		}else{ // Otherwise return false
			return false;
		}
		return true;
	}
}


#endif