/*
˼·һ�����޸�ԭ���飩��ͨ���Ƚ��������(m)�ǲ��ǵ���i������ǣ�����ɨ����һ�����֡���������������͵�m�����ֽ��бȽϣ�����͵�m��������ȣ����ҵ�һ���ظ������֡�������͵�m�����ֲ���ȣ��Ͱѵ�i�����ֺ͵�m�����ֽ�������m�ŵ���������λ�á����Ӷ�ΪO(n)
*/
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0)
			return false;
		for (int i = 0; i<length; i++)
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;

		for (int i = 0; i<length; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int tmp = numbers[i];
				numbers[i] = numbers[tmp];
				numbers[tmp] = tmp;
			}
		}
		return false;
	}
};
