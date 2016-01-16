#include "utils.hpp"
#include <vector>
using std::vector;
class Solution {
public:
	/*
	Given two sorted integer arrays A and B, merge B into A as one sorted array.
	Note: You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively
	*/
	static vector<int> MergeSortedArr(vector<int>& vec1, vector<int>& vec2) {
				
		int n1 = vec1.size()-1;
		int n2 = vec2.size()-1;
		int k = vec1.size()+vec2.size()-1;
		
		vec1.resize(vec1.size()+vec2.size(), 0);
				
		while(n1 >= 0 && n2 >= 0) {
			if(vec1[n1] > vec2[n2]) {
				vec1[k--] = vec1[n1--];
			}else {
				vec1[k--] = vec2[n2--];
			}
		}
		
		while(n1 >= 0) {
			vec1[k--] = vec1[n1--];
		}
		
		while(n2 >= 0) {
			vec1[k--] = vec2[n2--];
		}
		
		return vec1;		
		
	}
};

int main(){
	vector<int> vec1{1,2,3,4,5};
	vector<int> vec2{1,2,3,4,5, 6};
	printArr(vec1);
	printArr(vec2);
	
	Solution::MergeSortedArr(vec1, vec2);
	
	printArr(vec1);
	printArr(vec2);
	
			
	return 0;
}