class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;

		int pre1 = 1, pre2 = 1;
		int cur;
		for (int i = 2; i <= number; i++)
		{
			cur = pre1 + pre2;

			pre2 = pre1;
			pre1 = cur;
		}

		return cur;
	}
};
