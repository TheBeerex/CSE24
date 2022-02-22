// Author: Cameron Tobin

#include <iostream>
#include <cmath>

using namespace std;

// Utility to find the position of a minimum value of an int array
int findMinPos(int* arr, int start, int end){
	int min = arr[start];
	int minPos = start;
	for(int i = start+1; i <= end; i++){
		if (arr[i] < min){
			min = arr[i];
			minPos = i;
		}
	}
	return minPos;
}

// Utility to find the position of a maximum value of an int array
int findMaxPos(int* arr, int start, int end){
	int min = arr[start];
	int minPos = start;
	for(int i = start+1; i <= end; i++){
		if (arr[i] > min){
			min = arr[i];
			minPos = i;
		}
	}
	return minPos;
}

int profit(int* prices, int size, int money){
	int buyPos;
	int sellPos;

	buyPos = findMinPos(prices, 0, size-1); // buyPos is the minimum of the list of prices

	if(buyPos != size-1){ // If the buyPos is not at the end of the list of prices
		sellPos = findMaxPos(prices, buyPos, size-1); // sellPos will be the maximum from buyPos to size-1
	}else{
		return 0; // Otherwise our profit is 0
	}

	int stockCount = floor(money / prices[buyPos]);
	int profit = (stockCount * prices[sellPos]) - (stockCount * prices[buyPos]);

	return profit;
}

int profit_max(int* prices, int size, int money){
	int profit = money;

	int buyPos = 0;
	int sellPos = 0;
	// Loop through the size of the array searching for profit.
	while(buyPos < size-1){
		buyPos = findMinPos(prices, 0, size-1); // buyPos is the minimum of the list of prices

		if(buyPos != size-1){ // If the buyPos is not at the end of the list of prices
			sellPos = findMaxPos(prices, buyPos, size-1); // sellPos will be the maximum from buyPos to size-1
		}else{
			break;
		}
		int stockCount = floor(profit / prices[buyPos]);
		
		profit += (stockCount * prices[sellPos]) - (stockCount * prices[buyPos]);
	}

	return (profit - money);
}

int main(){
	// Basic profit
	int prices1[7] = {7,1,5,3,6,4,5};

	cout << profit(prices1, 7, 10) << endl;

	int prices2[7] = {7, 6, 5, 4, 3, 2, 1};

	cout << profit(prices2, 7, 10) << endl;

	int prices3[7] = {7, 3, 3, 4, 6, 12, 5};

	cout << profit(prices3, 7, 2) << endl << endl;

	// MAXIMUM PROFITS (taken roughly from the last month of NYSE:RBLX)
	int prices4[22] = {65, 65, 67, 71, 71, 68, 71, 72, 75, 82, 75, 80, 76, 72, 69, 72, 70, 72, 75, 74, 76, 76};

	cout << profit(prices4, 22, 150) << endl;

	return 0;
}
/*
Written component (not bonus)
=================
- Give a high level description of your solution.
	+	My solution first finds the minimum of the given array of prices, then finds the maximum from the position of the minimum to the end of the array. It then calculates how many shares you could purchase at the minimum and uses that to calculate the profit (amount * maximum - amount * minimum).
- What is the order of complexity of your solution? Explain how you calulated the order of complexity by referring to specific lines of your code.
	+	The order of complexity of my solutionn is O(n) since at it doesn't have nested loops. Specifically when I call findMinPos() and findMaxPos() does the function's complexity grow with the size of the input.
*/
