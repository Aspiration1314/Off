/*用两个数字small和big分别表示序列的最大值和最小值，首先将small初始化为1，end初始化为2.
如果从small到big的和大于s，我们就从序列中去掉较小的值(即增大small)
相反，只需要增大big。终止条件为：一直增加small到(1+sum)/2并且big小于sum为止*/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		if (sum < 3)
			return result;

		int small = 1;
		int big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;
		while (small < middle) //这里一定是小于，不能是小于等于
		{
			if (curSum == sum)
				insertIntoResult(result, small, big);

			while (curSum > sum && small < middle)
			{
				curSum -= small;
				++small;
				if (curSum == sum)
					insertIntoResult(result, small, big);
			}
			++big;
			curSum += big;
		}
		return result;
	}

private:
	void insertIntoResult(vector<vector<int> > &result, int small, int big)
	{
		vector<int> tmpSeq;
		for (int i = small; i <= big; i++)
			tmpSeq.push_back(i);

		result.push_back(tmpSeq);
	}
};
