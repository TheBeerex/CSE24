#ifndef CLASSWORK_H
#define CLASSWORK_H

//Sum
int sum(int arr[], int size){
	int out = 0;
	for(int i=0; i < size; i++){
		out += arr[i];
	}
	return out;
}

#endif