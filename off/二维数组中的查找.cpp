/* ˼·�� ���αȽ����Ͻǵ����֣���������ִ���Ҫ���ҵ����֣����޳��У���������ִ���Ҫ���ҵ����֣����޳��У�
���Ӷȣ�O(m+n), ����m������n */
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
