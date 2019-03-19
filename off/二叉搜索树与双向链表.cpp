/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
/*解题思路：递归版
1.将左子树构造成双链表，并返回链表头节点。2.定位至左子树双链表最后一个节点。3.如果左子树链表不为空的话，将当前root追加到左子树链表。4.将右子树构造成双链表，并返回链表头节点。5.如果右子树链表不为空的话，将该链表追加到root节点之后。6.根据左子树链表是否为空确定返回的节点。*/
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
