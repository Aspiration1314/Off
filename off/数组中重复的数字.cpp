/*
思路一（会修改原数组）：通过比较这个数字(m)是不是等于i，如果是，接着扫描下一个数字。如果不是则拿它和第m个数字进行比较，如果和第m个数字相等，则找到一个重复的数字。如果它和第m个数字不相等，就把第i个数字和第m个数字交换，把m放到属于它的位置。复杂度为O(n)
*/
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0)
			return false;
		for (int i = 0; i<length; i++)
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;

		for (int i = 0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}
		return false;
	}
};
