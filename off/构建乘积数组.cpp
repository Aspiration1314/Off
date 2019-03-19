/*
˼·һ��ֱ�������˵Ļ������Ӷ�ΪO(n^2);
˼·�������乹��Ϊһ������(�Խ�ֵȫΪ1)��������ߣ��������£������˽���������ұߣ��������ϣ������˽����
������������˼��ɣ����Ӷ�ΪO(n);
*/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int length = A.size();
		vector<int> B;
		if (length <= 0)
			return B;

		for (int i = 0; i<length; i++)
			B.push_back(1);

		for (int i = 1; i<length; i++)
			B[i] = B[i - 1] * A[i - 1];

		int tmp = 1;
		for (int i = length - 2; i >= 0; i--)
		{
			tmp *= A[i + 1];
			B[i] *= tmp;
		}
		return B;
	}
};
