
/*˼·���������������������ͷβ����ָ��i��j��
��ai + aj == sum�����Ǵ𰸣����ԽԶ�˻�ԽС��
��ai + aj > sum��j -= 1
��ai + aj < sum��i += 1 */
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> result;
		int length = array.size();
		if (length < 2)
			return result;
		int start = 0;
		int end = length - 1;
		// sort(array.begin(), array.end());
		while (start < end)
		{
			int curSum = array[start] + array[end];
			if (curSum == sum)
			{
				result.push_back(array[start]);
				result.push_back(array[end]);
				return result;
			}
			else if (curSum < sum)
				++start;
			else
				--end;
		}
		return result;
	}
};
