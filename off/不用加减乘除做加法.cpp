/*
考虑位运算，分三步：
第一步：不进位加 n1
第二步：计算进位 n2
第三步：n1 和 n2 求和（重复第一步，直到进位为0，即n2=0)
在第一步中，采用异或
第二步中，采用按位与，左移一位
*/
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		do
		{
			sum = num1 ^ num2; //异或
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return num1;
	}
};
