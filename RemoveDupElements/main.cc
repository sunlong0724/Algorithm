#include "utils.hpp"
class Solution {
public:
	/*
	Given a sorted array, remove the duplicates in place such that > each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	For example, Given input array A = [1,1,2],
	Your function should return length = 2, and A is now [1,2].
	*/
	static int removeDupElement(int A[], int n) {
		/*
		int j = 0; 
		for (int i = 1; i < n; ++i) {
			if (A[i] == A[i-1])
				continue;
			A[++j] = A[i];
		}
		*/
		
		int j = 0; 
		for (int i = 1; i < n; ++i) {
			if (A[j] != A[i]){
				A[++j] = A[i];
			}
		}
				
		return j+1;
	}
};

int main(){
	int A[] = {1,2,3,3,4,5};
	int len;
	printArr(A, sizeof(A)/sizeof(int));
	len = Solution::removeDupElement(A, sizeof(A)/sizeof(int));
	printArr(A, len);
	return 0;
}