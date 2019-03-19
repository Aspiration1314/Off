/*思路：借助哈希表，但是空间复杂度为O(1)，时间复杂度为O(n); */
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() <= 0)
			return -1;
		int tableSize = 256;
		vector<int> numOfChar(tableSize, 0);

		for (int i = 0; i<str.size(); i++)
			++numOfChar[str[i]];

		for (int i = 0; i<str.size(); i++)
		if (numOfChar[str[i]] == 1 && str[i] != '\0')
			return i;

		return -1;
	}
};
