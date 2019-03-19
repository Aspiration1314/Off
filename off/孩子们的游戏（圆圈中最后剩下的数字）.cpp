/*
˼·һ����STL��std::list��ģ����������б�����list������һ�����εĽṹ�����ÿ�ε�����ɨ�赽�б�ĩβ��ʱ��Ҫ�ǵðѵ������Ƶ��б��ͷ�����������ǰ���һ��ԲȦ��˳������������б��ˡ�����˼·��Ҫһ����n�����Ļ����б���ģ�����ɾ���Ĺ��̣�����ڴ濪��ΪO(n)���������ַ���ÿɾ��һ��������Ҫm�����㣬�ܹ���n�����֣�����ܵ�ʱ�临�Ӷ���O(mn)��
˼·������ѧ���ɷ�
{  0                  n=1
f(n,m)={
{  [f(n-1,m)+m]%n     n>1
ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)�ķ�����
*/
//˼·һ
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

//˼·��
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
