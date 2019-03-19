/* 思路:创建数组保存已经找到的丑数，空间换时间； */
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;

		vector<int> res(index);
		res[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;

		for (int i = 1; i<index; i++)
		{
			res[i] = min(2 * res[t2], min(3 * res[t3], 5 * res[t5]));

			while (res[i] >= 2 * res[t2]) ++t2;
			while (res[i] >= 3 * res[t3]) ++t3;
			while (res[i] >= 5 * res[t5]) ++t5;
		}
		return res[index - 1];
	}
};
