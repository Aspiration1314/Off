/************ �򵥷��� ************/
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

/******* ����� *******/
˼·��һ��������ȥ1������ԭ�����������㣬�Ὣ���ұߵ�һ��1���0.
��ô���������ж��ٸ�1���ɽ��������Ĳ������ٴΣ�
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
