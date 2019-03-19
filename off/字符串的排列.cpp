/*全排列问题*/
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.size() <= 0)
			return result;
		PermutationCore(result, str, 0);
		sort(result.begin(), result.end());
		return result;
	}

	void PermutationCore(vector<string> &result, string str, int begin)
	{
		if (begin == str.size() - 1)
			result.push_back(str);
		else
		{
			for (int i = begin; i<str.size(); i++)
			{
				if (i != begin && str[i] == str[begin])
					continue;
				swap(str[i], str[begin]);
				PermutationCore(result, str, begin + 1);
				swap(str[i], str[begin]);
			}
		}
	}
};
