/*
����λ���㣬��������
��һ��������λ�� n1
�ڶ����������λ n2
��������n1 �� n2 ��ͣ��ظ���һ����ֱ����λΪ0����n2=0)
�ڵ�һ���У��������
�ڶ����У����ð�λ�룬����һλ
*/
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		do
		{
			sum = num1 ^ num2; //���
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return num1;
	}
};
