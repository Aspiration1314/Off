/* 思路：首先计算原字符串长度，空格个数；然后计算替换之后的长度；设置两个指针分别指向原，新字符串的尾部，逐个赋值；
复杂度：O(n) */
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;

		int original_length = 0;
		int number_of_space = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++original_length;
			if (str[i] == ' ')
				++number_of_space;
			++i;
		}

		if (number_of_space <= 0)
			return;

		int new_length = original_length + 2 * number_of_space;

		int index_of_original = original_length;
		int index_of_new = new_length;

		while (index_of_original >= 0 && index_of_new >= index_of_original)
		{
			if (str[index_of_original] == ' ')
			{
				str[index_of_new--] = '0';
				str[index_of_new--] = '2';
				str[index_of_new--] = '%';
			}
			else
			{
				str[index_of_new--] = str[index_of_original];
			}
			--index_of_original;
		}

	}
};
