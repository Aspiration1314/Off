/*
思路一：直接用连乘的话，复杂度为O(n^2);
思路二：将其构建为一个矩阵(对角值全为1)，先求左边（从上往下）的连乘结果，在求右边（从下往上）的连乘结果；
左右两侧结果相乘即可；复杂度为O(n);
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
