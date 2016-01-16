#include "utils.hpp"
class Solution {
public:
	/*
	Given an array and a value, remove all instances of that > value in place and return the new length.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
	*/
	static int removeElement(int A[], int n, int elem) {
		int j = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i] == elem) 
				continue;
			
			A[j] = A[i];
			++j;	
		}	
		return j;
	}
};

int main(){
	int A[] = {1,2,2,3,2,2,2,4,5};
	int len;
	printArr(A, sizeof(A)/sizeof(int));
	len = Solution::removeElement(A, sizeof(A)/sizeof(int), 2);
	printArr(A, len);
	return 0;
}