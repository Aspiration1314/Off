/*˼·�����ڶ��ֲ��Ҹ��Ӷ�ΪO(logn)�����ֲ��ҿ�ʼλ�ã����ֲ��ҽ�βλ�ã����*/
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int length = data.size();
		if (length <= 0)
			return 0;

		int first = firstIndex(data, k);
		int last = lastIndex(data, k);
		if (first > -1 && last > -1)
			return last - first + 1;

		return 0;
	}

	int firstIndex(vector<int> data, int k)
	{
		int low = 0;
		int high = data.size() - 1;
		int midIndex, midData;
		while (low <= high)
		{
			midIndex = (low + high) / 2;
			midData = data[midIndex];

			if (midData == k)
			{
				if (midIndex == 0 || data[midIndex - 1] != k)
					return midIndex;
				else
					high = midIndex - 1;
			}
			else if (midData > k)
				high = midIndex - 1;
			else
				low = midIndex + 1;
		}
		return -1;
	}

	int lastIndex(vector<int> data, int k)
	{
		int low = 0;
		int high = data.size() - 1;
		int midIndex, midData;
		while (low <= high)
		{
			midIndex = (low + high) / 2;
			midData = data[midIndex];

			if (midData == k)
			{
				if (midIndex == data.size() - 1 || data[midIndex + 1] != k)
					return midIndex;
				else
					low = midIndex + 1;
			}
			else if (midData > k)
				high = midIndex - 1;
			else
				low = midIndex + 1;
		}
		return -1;
	}
};
