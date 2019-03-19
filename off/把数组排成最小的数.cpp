/*思路：通过字符串解决大数问题，然后通过自定义的字符串比较规则，对字符串排序*/
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.size()<1)
			return string();

		string result;
		vector<string> numberString;
		for (int i = 0; i<numbers.size(); i++)
		{
			stringstream ss;
			ss << numbers[i];
			string s = ss.str();
			numberString.push_back(s);
		}
		sort(numberString.begin(), numberString.end(), Compare);

		for (int i = 0; i<numberString.size(); i++)
			result.append(numberString[i]);

		return result;
	}

	static bool Compare(const string &str1, const string &str2)
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1<s2;
	}
};
