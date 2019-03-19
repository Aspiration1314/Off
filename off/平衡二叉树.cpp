/* 递归判断左右子树的方法重复计算太多；
下面的方法相当于从叶节点向上遍历，只需要遍历一次。记录每个结点到叶节点的长度； */
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return true;
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}

private:
	bool IsBalanced(TreeNode *pRoot, int *depth)
	{
		if (pRoot == nullptr)
		{
			*depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
		{
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				*depth = left>right ? (left + 1) : (right + 1);
				return true;
			}
		}
		return false;
	}
};
