/* 递归判断：左子树<根节点<右子树，不满足则为false，否则为true； */
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() <= 0)
			return false;
		int start = 0, end = sequence.size() - 1;
		return isLastOrder(sequence, start, end);
	}

private:
	bool isLastOrder(vector<int> &sequence, int start, int end)
	{
		if (start > end)
			return false;

		int root = sequence[end];
		int i = start;
		for (; i<end; i++)
		{
			if (sequence[i]>root)
				break;
		}
		int j = i;
		for (; j<end; j++)
		{
			if (sequence[j]<root)
				return false;
		}
		bool left = true;
		if (i - 1 > start)
			left = isLastOrder(sequence, start, i - 1);

		bool right = true;
		if (i < end - 1)
			right = isLastOrder(sequence, i, end - 1);

		return(left && right);
	}

};
