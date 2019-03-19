/* 思路：两次翻转 */
class Solution {
public:
	string ReverseSentence(string str) {
		int len = str.size();
		if (len <= 0)
			return str;
		reverseString(str, 0, len - 1);

		int i = 0, j = 0;
		while (j <= len)
		{
			if (str[j] == ' ' || j == len)
			{
				reverseString(str, i, j - 1);
				i = j + 1;
				j = i + 1;
			}
			else
				++j;
		}
		return str;
	}

	void reverseString(string &str, int start, int end)
	{
		for (int i = start, j = end; i<j; i++, j--)
			swap(str[i], str[j]);
	}
};
