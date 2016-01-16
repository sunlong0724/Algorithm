#include "utils.hpp"
#include <vector>
using std::vector;
class Solution {
public:
	/*
	Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
	*/
	static vector<int> plusOne(vector<int>& vec) {
		
		vector<int> res(vec.size(), 0);
				
		int one = 1;
		for (int i = vec.size()-1; i >= 0; --i) {
			int sum = vec[i]+one;
			res[i] = sum%10;		
			one = sum/10;		
			
		}
		if (one > 0) {
			res.insert(res.begin(), 1);
		}
		
		return res;
	}
};

int main(){
	vector<int> vec{1,2,3,4,5};
	printArr(vec);
	printArr(Solution::plusOne(vec));
		
	vec.push_back(9);	
	printArr(vec);
	printArr(Solution::plusOne(vec));
	
	vector<int> vec2{9,9,9,9,9,9};
	printArr(vec2);
	printArr(Solution::plusOne(vec2));
		
	return 0;
}