˼·����ʵ�Ǹ������⣬����n��̨�ף���n - 1����϶��������0~n - 1������ָc(n - 1, 0) + c(n - 1, 1) + ... + c(n - 1, n - 1) = 2 ^ (n - 1)������c��ʾ��ϡ� ��������λ1 << --number���������ġ�

class Solution {
public:
	int jumpFloorII(int number) {
		int jump_number = 1;
		for (int i = 0; i<number - 1; i++)
			jump_number = jump_number * 2;
		return jump_number;
	}
};


/**********���Ӽ򵥵ķ���**********/

class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (--number);
	}
};
