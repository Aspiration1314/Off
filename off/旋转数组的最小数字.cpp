/*简单方法*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{         //数组为空时
		if (rotateArray.size() == 0)
			return -1;
		//前部分数据旋转
		for (int i = 0; i < rotateArray.size() - 1; i++)
		{
			if (rotateArray[i] > rotateArray[i + 1])
				return rotateArray[i + 1];
		}
		//全部数据旋转，相当于没有旋转，最小数即为第一个数
		return rotateArray[0];
	}
};

/*思路：二分查找思想*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int length = rotateArray.size();
		if (length == 0)
			return 0;

		int left = 0, right = length - 1;
		int mid;
		while (rotateArray[left] >= rotateArray[right])
		{
			if (left == right - 1)
				return rotateArray[right];

			mid = (left + right) / 2;

			if (rotateArray[left] == rotateArray[mid] &&
				rotateArray[mid] == rotateArray[right])
			{
				int min_num = rotateArray[left];
				for (int i = left; i < right; i++)
					min_num = rotateArray[i]<min_num ? rotateArray[i] : min_num;
				return min_num;
			}
			if (rotateArray[left] <= rotateArray[mid])
				left = mid;
			else
				right = mid;

		}
		return rotateArray[left];

	}
};


