/* 思路：
第一块有两种方式：横着放和竖着放
横这放对应为发f(n-2);
竖着放下一步的放方法为f(n-1);
所以总的放的方法为f(n)=f(n-1)+f(n-2);
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
