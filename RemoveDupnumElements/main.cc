#include "utils.hpp"
class Solution {
public:
	/*
	Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
	For example, Given sorted array A = [1,1,1,2,2,3],
	Your function should return length = 5, and A is now [1,1,2,2,3].
	*/
	static int removeDupnumElement(int A[], int n) {
		/*
		int j = 0; 
		for (int i = 1; i < n; ++i) {
			if (A[i] == A[i-1])
				continue;
			A[++j] = A[i];
		}
		*/
		
		int num=0;
		int j = 0; 
		for (int i = 1; i < n; ++i) {
			if (A[j] != A[i]){
				A[++j] = A[i];
				num = 0;
			}else {
				++num;
				if (num < 2) {
					A[++j] = A[i];	
				}
			}
		}
				
		return j+1;
	}
};

int main(){
	int A[] = {1,1,2,2,3,3,3,4,5};
	int len;
	printArr(A, sizeof(A)/sizeof(int));
	len = Solution::removeDupnumElement(A, sizeof(A)/sizeof(int));
	printArr(A, len);
	return 0;
}