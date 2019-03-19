/* ˼·���鲢����ĸĽ��������ݷֳ�ǰ����������(�ݹ�ֵ�ÿ���������һ��������)���ϲ����飬�ϲ�ʱ������ǰ�������ֵarray[i]���ں�������ֵarray[j]ʱ����ǰ������array[i]~array[mid]���Ǵ���array[j]�ģ�count += mid+1 - i�ο���ָOffer�����Ǹо���ָOffer�鲢��������һ���������̡����о��ǲ��������������Ƚϴ󣬶�ÿ�η��ص�count mod(1000000007)���� */
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
