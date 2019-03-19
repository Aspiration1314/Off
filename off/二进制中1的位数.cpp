/************ 简单方法 ************/
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		unsigned int flag = 1;
		while (flag)
		{
			if (n & flag)
				++count;
			flag = flag << 1;
		}
		return count;
	}
};

/******* 巧妙方法 *******/
思路：一个整数减去1，在与原整数做与运算，会将最右边的一个1变成0.
那么二进制中有多少个1，可进行这样的操作多少次；
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			++count;
			n = (n - 1)&n;
		}
		return count;
	}
};
