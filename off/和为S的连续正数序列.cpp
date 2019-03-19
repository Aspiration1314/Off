/*����������small��big�ֱ��ʾ���е����ֵ����Сֵ�����Ƚ�small��ʼ��Ϊ1��end��ʼ��Ϊ2.
�����small��big�ĺʹ���s�����Ǿʹ�������ȥ����С��ֵ(������small)
�෴��ֻ��Ҫ����big����ֹ����Ϊ��һֱ����small��(1+sum)/2����bigС��sumΪֹ*/
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
		while (small < middle) //����һ����С�ڣ�������С�ڵ���
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
