/*
#include <stdio.h>
int search(int array[], int n, int v)
{
    int left, right, middle;

    left = 0, right = n - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (array[middle] > v)
        {
            right = middle - 1;
        }
        else if (array[middle] < v)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int search_recurse(int array[], int low, int high, int v)
{
    int middle;

    middle = (low + high) / 2;

    if (low < high)
    {
        if (array[middle] > v)
        {
            return search_recurse(array, low, middle, v);
        }
        else if (array[middle] < v)
        {
            return search_recurse(array, middle + 1, high, v);
        }
        else
        {
            return middle;
        }
    }
    else if (low == high)
    {
        if (array[middle] == v)
        {
            return middle;
        }
        else
        {
            return -1;
        }

    }
    else
    {
        return -1;
    }

    return -1;
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 13, 19};

    int m = search(array, sizeof(array)/sizeof(array[0]), 13);

    printf("m = %d\n", m);

    m = search_recurse(array, 0, sizeof(array)/sizeof(array[0]), 13);

    printf("m = %d\n", m);

    return 0;
}
*/

#include <vector>
#include "utils.hpp"

using std::vector;

class Solution {
public:
	static int binarySearch(vector<int>& vec, int target) {
		int mid, right, left;
		left = 0;
		right = vec.size()-1;
		mid = (left + right) >> 1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (vec[mid] > target) {
				right = mid;
			}
			else if (vec[mid] < target) {
				left = mid;
			}
			else {
				return mid;
			}
		}
		return -1;
	}

	static int binarySearchRecursive(vector<int>& vec, int left, int right, int target) {
		int mid = (left + right) >> 1;
		if (left < right) {
			if (vec[mid] > target) {
				return binarySearchRecursive(vec, left, mid, target);
			}
			else if (vec[mid] < target) {
				return binarySearchRecursive(vec, mid, right, target);
			}
			else {
				return mid;
			}
		}
		else if (left == right) {
			if (vec[mid] == target) {
				return mid;
			}
			else {
				return -1;
			}
		}
		
	}
};

int main() {
	vector<int> vec{ 0, 1, 2, 3, 4, 7, 7, 7, 13, 19 };
	printArr(vec);
	int res = Solution::binarySearch(vec, 7);

	cout << "res : " << res << endl;

	res = Solution::binarySearchRecursive(vec, 0, vec.size() - 1, 7);
	cout << "res2 : " << res << endl;
}