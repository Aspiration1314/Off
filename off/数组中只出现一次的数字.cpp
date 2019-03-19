/*思路：可以用位运算实现，如果将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或的结果；
所以根据异或的结果1所在的最低位，把数字分成两半，每一半里都还有只出现一次的数据和成对出现的数据；
这样继续对每一半相异或则可以分别求出两个只出现一次的数字*/
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
