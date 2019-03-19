/*
思路一：用STL中std::list来模拟这个环形列表。由于list并不是一个环形的结构，因此每次跌代器扫描到列表末尾的时候，要记得把跌代器移到列表的头部。这样就是按照一个圆圈的顺序来遍历这个列表了。这种思路需要一个有n个结点的环形列表来模拟这个删除的过程，因此内存开销为O(n)。而且这种方法每删除一个数字需要m步运算，总共有n个数字，因此总的时间复杂度是O(mn)；
思路二：数学归纳法
{  0                  n=1
f(n,m)={
{  [f(n-1,m)+m]%n     n>1
时间复杂度为O(n)，空间复杂度为O(1)的方法；
*/
//思路一
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;

		unsigned int i = 0;

		list<int> integers;
		for (i = 0; i < n; ++i)
			integers.push_back(i);

		list<int>::iterator curinteger = integers.begin();
		while (integers.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				curinteger++;
				if (curinteger == integers.end())
					curinteger = integers.begin();
			}

			list<int>::iterator nextinteger = ++curinteger;
			if (nextinteger == integers.end())
				nextinteger = integers.begin();

			--curinteger;
			integers.erase(curinteger);
			curinteger = nextinteger;
		}

		return *(curinteger);
	}
};

//思路二
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m < 0)
			return -1;
		int lastinteger = 0;

		for (int i = 2; i <= n; i++)
			lastinteger = (lastinteger + m) % i;

		return lastinteger;
	}
};
