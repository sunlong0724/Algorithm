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

II:
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3, Return [1,3,3,1].
��ͬ����һ�⣬�������ǽ�����Ҫ�õ��ĵ�k��ļ��ϣ���ֻ��ʹ��O(k)�Ŀռ䡣���Բ�����ǰ���ά����ķ�ʽ��ֻ��ʹ��һλ����������㡣

�ڵ�һ�����棬����֪������˹�����ǵļ��㹫ʽ�������ģ�A[k][n] = A[k-1][n-1] + A[k-1][n]��

�������������ŵĵ�3������ݣ�[1, 3, 3, 1]�����������Ҫ�����4������ݣ�������Ǵ�ǰ������㣬Ʃ��A[4][2]= A[3][1] + A[3][2]��Ҳ����4��������Ϊֻ��һ�����飬������Ҫ��4���ֵ���ǵ�2���λ�ã���ô���Ǽ���A[4][3]��ʱ��ͻ���������ˣ���Ϊ��ʱ��A[3][2]����3������4�ˡ�

Ϊ�˽��������⣬����ֻ�ܴӺ���ǰ���㣬��Ȼ�������Ǹ����ӣ�����ʵ�ּ���A[4][3] = A[3][2] + A[3][3]��Ҳ����6�����ǽ�6ֱ�Ӹ��ǵ�3���λ�ã�������Ӱ�����Ǽ���A[4][2]����ΪA[4][2] = A[3][1] + A[3][2]���Ѿ������漰��3���λ���ˡ�

�������μ��㣬����ͺܼ��ˣ�
	*/
	static vector<int> generate(int rowIndex) {
		
		
		vector<int> vals;

        vals.resize(rowIndex + 1, 1);

        for(int i = 0; i < rowIndex + 1; ++i) {
            for(int j = i - 1; j >= 1; --j) {
                vals[j] = vals[j] + vals[j - 1];
            }

        }

        return vals;
		
		
	}
};

int main(){
	
	/*
	vector<vector<int>> res = Solution::generate(1);
		for (auto& vec : res)
			printArr(vec);
			
		res = Solution::generate(2);
		for (auto& vec : res)
			printArr(vec);
		
	res = Solution::generate(5);
		for (auto& vec : res)
			printArr(vec);
		*/
		
		printArr(Solution::generate(5));
	return 0;
}