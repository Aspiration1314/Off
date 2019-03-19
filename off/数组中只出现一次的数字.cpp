/*˼·��������λ����ʵ�֣����������������������������Ľ���϶���������ֻ����һ�ε��������Ľ����
���Ը������Ľ��1���ڵ����λ�������ֳַ����룬ÿһ���ﶼ����ֻ����һ�ε����ݺͳɶԳ��ֵ����ݣ�
����������ÿһ�����������Էֱ��������ֻ����һ�ε�����*/
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int length = data.size();
		if (length < 2)
			return;

		int xorNumber = 0;
		for (int i = 0; i<length; i++)
			xorNumber ^= data[i];

		int indexOf1 = findFirstBitIs1(xorNumber);

		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i<length; i++)
		{
			if (isBit1(data[i], indexOf1))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}

	int findFirstBitIs1(int number)
	{
		int indexBit = 0;
		while ((number & 1) == 0 && indexBit<8 * sizeof(int))
		{
			number = number >> 1;
			++indexBit;
		}
		return indexBit;
	}

	bool isBit1(int number, int indexBit)
	{
		number = number >> indexBit;
		return (number & 1);
	}
};
