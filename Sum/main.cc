#include "utils.hpp"
#include <vector>
using std::vector;
class Solution {
public:
	/*
	Given an array of intergers, find two numbers such that they add up to a specific target number. 
	The function twoSum should return indices of the two numbers such that they add up to the target, 
	where index1 must be less than index2 Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.
	Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
	*/
	static vector<int> Sum(vector<int>& vec1, int target) {
		int index1 = -1;
		int index2 = -1;
		
		for (int i = 0; i < vec1.size(); ++i) {
			index1 = i;
			int another = target - vec1[index1];
			for (int i = 0; i < vec1.size(); ++i) {
				if (another == vec1[i]){
					index2 = i;
					return {index1+1, index2+1};
				}
			}
			
		}
		
		
		return {index1, index2};		
	}
};

int main(){
	vector<int> vec1{1,2,3,4,5,6,9,10};
	int target = 14;
	printArr(vec1);
	
	
	vector<int> res = Solution::Sum(vec1, target);
	
	printArr(res);
	
	
			
	return 0;
}