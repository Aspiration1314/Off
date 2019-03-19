/*一个思路是基于快排中partition（会修改数组中的值）；
还有就是：定义一个times记录当前牟数字出现的次数，如果小于0则替换；
复杂度都是O(n)
*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() <= 0)
			return 0;
		int result = numbers[0];
		int times = 1;

		for (int i = 0; i<numbers.size(); i++)
		{
			if (times == 0)
			{
				result = numbers[i];
				times = 1;
			}
			else if (times>0 && result == numbers[i])
				++times;
			else
				--times;
		}
		if (!isMoreThanHalf(numbers, result))
			return 0;

		return result;

	}

private:
	bool isMoreThanHalf(vector<int> numbers, int result)
	{
		int times = 0;
		for (int i = 0; i<numbers.size(); i++)
		if (numbers[i] == result)
			++times;
		if (2 * times <= numbers.size())
			return false;
		return true;
	}
};
