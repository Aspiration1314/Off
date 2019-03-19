/*复杂度为O(n logn)*/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (input.size()<k || k<1)
			return result;

		sort(input.begin(), input.end());

		for (int i = 0; i<k; i++)
			result.push_back(input[i]);
		return result;
	}
};

/*复杂度为O(nlogk), 基于红黑树*/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.size()<k || k<0)
			return vector<int>();

		multiset<int, greater<int>> leastNumbers;
		vector<int>::const_iterator iter = input.begin();
		for (; iter != input.end(); iter++)
		{
			if (leastNumbers.size() < k)
				leastNumbers.insert(*iter);
			else
			{
				multiset<int, greater<int>>::iterator iterGreatest = leastNumbers.begin();
				if (*iter < *iterGreatest)
				{
					leastNumbers.erase(*iterGreatest);
					leastNumbers.insert(*iter);
				}
			}
		}
		return vector<int>(leastNumbers.begin(), leastNumbers.end());
	}
};
