/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
/*����˼·���ݹ��
1.�������������˫��������������ͷ�ڵ㡣2.��λ��������˫�������һ���ڵ㡣3.�������������Ϊ�յĻ�������ǰroot׷�ӵ�����������4.�������������˫��������������ͷ�ڵ㡣5.�������������Ϊ�յĻ�����������׷�ӵ�root�ڵ�֮��6.���������������Ƿ�Ϊ��ȷ�����صĽڵ㡣*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;

		pRootOfTree = ConvertNode(pRootOfTree);
		while (pRootOfTree->left != nullptr)
			pRootOfTree = pRootOfTree->left;

		return pRootOfTree;
	}

	TreeNode* ConvertNode(TreeNode *pRoot)
	{
		if (pRoot == nullptr)
			return nullptr;
		if (pRoot->left != nullptr)
		{
			TreeNode *left = ConvertNode(pRoot->left);
			while (left->right != nullptr)
				left = left->right;
			pRoot->left = left;
			left->right = pRoot;
		}
		if (pRoot->right != nullptr)
		{
			TreeNode *right = ConvertNode(pRoot->right);
			while (right->left != nullptr)
				right = right->left;

			pRoot->right = right;
			right->left = pRoot;
		}
		return pRoot;
	}
};
