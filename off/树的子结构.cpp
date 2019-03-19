/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

/*���������жϸ��ڵ��Ƿ���ȣ��ж��ӽṹ�Ƿ����*/
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != nullptr && pRoot2 != nullptr)
		{
			if (pRoot1->val == pRoot2->val)
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->left, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
	bool DoesTree1HaveTree2(TreeNode *Tree1, TreeNode *Tree2)
	{
		if (Tree2 == nullptr)
			return true;
		if (Tree1 == nullptr)
			return false;
		if (Tree1->val != Tree2->val)
			return false;
		return DoesTree1HaveTree2(Tree1->left, Tree2->left) &&
			DoesTree1HaveTree2(Tree1->right, Tree2->right);
	}
};
