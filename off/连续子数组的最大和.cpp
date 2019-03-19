/* 思路：动态规划复杂度为O(n)， 首先定义一个值保存当前最大值；
如果当前和为负数，直接舍弃；如果不为负数，则累加；得到 当前和 与 当前最大值 比较*/
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() < 1)
			return 0;

		int curSum = array[0];
		int greatestSum = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			if (curSum < 0)
				curSum = array[i];
			else
				curSum += array[i];

			if (greatestSum < curSum)
				greatestSum = curSum;
		}
		return greatestSum;
	}
};
