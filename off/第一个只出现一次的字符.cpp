/*˼·��������ϣ�����ǿռ临�Ӷ�ΪO(1)��ʱ�临�Ӷ�ΪO(n); */
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
