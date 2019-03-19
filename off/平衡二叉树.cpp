/* �ݹ��ж����������ķ����ظ�����̫�ࣻ
����ķ����൱�ڴ�Ҷ�ڵ����ϱ�����ֻ��Ҫ����һ�Ρ���¼ÿ����㵽Ҷ�ڵ�ĳ��ȣ� */
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
