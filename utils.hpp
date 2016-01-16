#ifndef _UTILS_H_PP_
#define _UTILS_H_PP_

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void printArr(const vector<int>& vec) {
	cout << "The arr size is " << vec.size() << ", elements are (" ;
	for each (auto val in vec) {
		cout << val << ", ";
	}
	cout << ")" <<  endl;
}

void printArr(int* arr, int len) {
	cout << "The arr size is " << len << ", elements are (" ;
	for (int i = 0; i < len; ++i){
		cout << arr[i] << ", ";
	}
	cout << ")" <<  endl;
}

#endif