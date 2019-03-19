/*
1.����������
2.ͳ��0�ĸ�����
3.ͳ�Ƽ������
4.�Ա�nZ��nG��
*/
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int length = numbers.size();
		if (length < 5)
			return false;

		sort(numbers.begin(), numbers.end());

		int i, numberOfZero = 0, numberOfGap = 0;
		for (i = 0; i<length && numbers[i] == 0; i++)
			++numberOfZero;

		int small = i, big = small + 1;
		while (big < length)
		{
			if (numbers[small] == numbers[big])
				return false;
			numberOfGap += numbers[big] - numbers[small] - 1;
			++small;
			++big;
		}
		return numberOfZero >= numberOfGap ? true : false;
	}
};
