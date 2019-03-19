/* ˼·����̬�滮���Ӷ�ΪO(n)�� ���ȶ���һ��ֵ���浱ǰ���ֵ��
�����ǰ��Ϊ������ֱ�������������Ϊ���������ۼӣ��õ� ��ǰ�� �� ��ǰ���ֵ �Ƚ�*/
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
