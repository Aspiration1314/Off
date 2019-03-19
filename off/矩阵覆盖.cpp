/* ˼·��
��һ�������ַ�ʽ�����ŷź����ŷ�
����Ŷ�ӦΪ��f(n-2);
���ŷ���һ���ķŷ���Ϊf(n-1);
�����ܵķŵķ���Ϊf(n)=f(n-1)+f(n-2);
*/

class Solution {
public:
	int rectCover(int number) {
		if (number <= 2)
			return number;
		int pre1 = 2, pre2 = 1;
		int cur;
		for (int i = 2; i<number; i++)
		{
			cur = pre1 + pre2;

			pre2 = pre1;
			pre1 = cur;
		}
		return cur;
	}
};
