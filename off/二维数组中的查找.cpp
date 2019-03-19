/* 思路： 依次比较右上角的数字；如果该数字大于要查找的数字，则剔除列；如果该数字大于要查找的数字，则剔除行；
复杂度：O(m+n), 行数m，列数n */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		bool found = false;
		if (array.empty())
			return found;
		int rows, columns, row, column;
		rows = array.size();
		columns = array[0].size();
		row = 0;
		column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (array[row][column] == target)
			{
				found = true;
				break;
			}
			else if (array[row][column] > target)
				--column;
			else
				++row;
		}
		return found;
	}
};
