/* 思路：三次翻转 */
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len < 0 || len < n)
			return str;
		for (int i = 0, j = n - 1; i<j; i++, j--)
			swap(str[i], str[j]);
		for (int i = n, j = len - 1; i<j; i++, j--)
			swap(str[i], str[j]);
		for (int i = 0, j = len - 1; i<j; i++, j--)
			swap(str[i], str[j]);
		return str;
	}
};


/*************** 也可以写函数 **************/

class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len < 0 || len < n)
			return str;

		reverseString(str, 0, n - 1);
		reverseString(str, n, len - 1);
		reverseString(str, 0, len - 1);

		return str;
	}
	void reverseString(string &str, int start, int end)
	{
		for (int i = start, j = end; i<j; i++, j--)
			swap(str[i], str[j]);
	}
};
