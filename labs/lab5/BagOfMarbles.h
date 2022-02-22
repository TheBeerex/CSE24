// Author: beerex

#ifndef BAGOFMARBLES_H
#define BAGOFMARBLES_H

#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <time.h>

struct BagOfMarbles{
	int types[5] = {0,0,0,0,0};
	int totalMarbles = 0;

	BagOfMarbles(int arr[], int s){ // Constructor does not assume the items in arr[] are integers 0-4, instead opting for some input validation.
		for(int i = 0; i < s; i++){
			switch(arr[i]){
				case 0 :
					types[0]++;
					totalMarbles++;
					break;
				case 1 :
					types[1]++;
					totalMarbles++;
					break;
				case 2 :
					types[2]++;
					totalMarbles++;
					break;
				case 3 :
					types[3]++;
					totalMarbles++;
					break;
				case 4 :
					types[4]++;
					totalMarbles++;
					break;
			}
		}
	}

	int pick(){
		// Pick a marble at random, return its type (an int 0-4). If it is an empty bag, return -1.
		std::random_device rd;
		std::mt19937 rng(rd());
		
		// Empty bag check
		if(totalMarbles <= 0){
			return -1;
		}

		// Find a marble in the bag.
		int checkType = 0;
		while(true){
			std::uniform_int_distribution<> uni(0, 4);
			checkType = uni(rng); // Pick a marble type (an int 0-4)
			if(types[checkType] > 0){ // If there is a non-zero probability of picking that marble, test the probability of picking that marble.
				std::uniform_int_distribution<> uni(1, totalMarbles);
				if( uni(rng) <= types[checkType]){ // If said test succeeds, we have found our marble.
					// Remove the marble from the bag.
					types[checkType]--;
					totalMarbles--;
					break;
				}
			}
		}
		return checkType;
	}

	// Utility function to print the contents of the BagOfMarbles
	void print(){
		for(int i = 0; i < 5; i++){
			std::cout << types[i] << "  ";
		}
		std::cout << std::endl;

		std::cout << totalMarbles << std::endl;
	}
};

#endif