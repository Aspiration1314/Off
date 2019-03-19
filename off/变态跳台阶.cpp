思路：其实是隔板问题，假设n个台阶，有n - 1个空隙，可以用0~n - 1个隔板分割，c(n - 1, 0) + c(n - 1, 1) + ... + c(n - 1, n - 1) = 2 ^ (n - 1)，其中c表示组合。 有人用移位1 << --number，这是最快的。

class Solution {
public:
	int jumpFloorII(int number) {
		int jump_number = 1;
		for (int i = 0; i<number - 1; i++)
			jump_number = jump_number * 2;
		return jump_number;
	}
};


/**********更加简单的方法**********/

class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (--number);
	}
};
