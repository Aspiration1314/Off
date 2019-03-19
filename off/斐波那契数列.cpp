/* ˼·�� ѭ���������м������ݹ�Ļ����ظ�����̫�ࣩ*/
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		int fib1 = 1, fib2 = 0;
		int fibn;
		for (int i = 2; i <= n; i++)
		{
			fibn = fib1 + fib2;

			fib2 = fib1;
			fib1 = fibn;
		}
		return fibn;
	}
};
