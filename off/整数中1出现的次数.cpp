/*Ë¼Â·£ºÇî¾Ù*/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 1)
			return 0;

		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			count += NumberOfN(i);
		}
		return count;
	}
	int NumberOfN(int n)
	{
		int count = 0;
		while (n)
		{
			if (n % 10 == 1)
				count += 1;
			n = n / 10;
		}
		return count;
	}

};
