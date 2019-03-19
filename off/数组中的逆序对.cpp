/* 思路：归并排序的改进，把数据分成前后两个数组(递归分到每个数组仅有一个数据项)，合并数组，合并时，出现前面的数组值array[i]大于后面数组值array[j]时；则前面数组array[i]~array[mid]都是大于array[j]的，count += mid+1 - i参考剑指Offer，但是感觉剑指Offer归并过程少了一步拷贝过程。还有就是测试用例输出结果比较大，对每次返回的count mod(1000000007)求余 */
class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size();
		if (length <= 0)
			return 0;
		int count = MergeSort(data, 0, length - 1);
		return count % 1000000007;
	}

	int MergeSort(vector<int> &data, int start, int end)
	{
		if (start >= end)
			return 0;

		int mid = (start + end) / 2;
		int left = MergeSort(data, start, mid);
		int right = MergeSort(data, mid + 1, end);

		vector<int> copy(data);
		int i = mid;
		int j = end;
		int counts = 0;
		int indexCopy = end;
		while (i >= start && j >= mid + 1)
		{
			if (data[i] > data[j])
			{
				copy[indexCopy--] = data[i--];
				counts += (j - mid);
			}
			else
				copy[indexCopy--] = data[j--];
		}

		while (i >= start)
			copy[indexCopy--] = data[i--];
		while (j >= mid + 1)
			copy[indexCopy--] = data[j--];

		for (int k = start; k <= end; k++)
			data[k] = copy[k];

		return left + right + counts;
	}
};
