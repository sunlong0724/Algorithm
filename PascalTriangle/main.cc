#include "utils.hpp"
#include <vector>
using std::vector;
class Solution {
public:
	/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5, Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
	*/
	static vector< vector<int> > generate(int numRows) {
		if (numRows == 1) 
			return {{1}};
		
		vector<vector<int>> res;
		res.push_back({1});	
		
		for (int i = 1; i < numRows; ++i) {
			vector<int> vec = {1};
			
			for (int j = 1; j < i; ++j){
				vec.push_back(res[i-1][j-1]+res[i-1][j]);
			}
			
			vec.push_back(1);
			res.push_back(vec);
		}
			
		return res;
	}
};

int main(){
	
	
	vector<vector<int>> res = Solution::generate(1);
		for (auto& vec : res)
			printArr(vec);
			
		res = Solution::generate(2);
		for (auto& vec : res)
			printArr(vec);
		
	res = Solution::generate(15);
		for (auto& vec : res)
			printArr(vec);
		
	return 0;
}