/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
/* 思路：相当于树的遍历 */
/*-------------- 递归方法 ------------*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr))
			return;

		if (pRoot->left != nullptr)
			Mirror(pRoot->left);
		if (pRoot->right != nullptr)
			Mirror(pRoot->right);
		TreeNode *temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
	}
};

/*------------- 使用栈 ------------------*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr))
			return;

		stack<TreeNode*> stackNodes;
		stackNodes.push(pRoot);

		while (stackNodes.size() > 0)
		{
			TreeNode *pNode = stackNodes.top();
			stackNodes.pop();

			TreeNode *pTemp = pNode->left;
			pNode->left = pNode->right;
			pNode->right = pTemp;

			if (pNode->left != nullptr)
				stackNodes.push(pNode->left);
			if (pNode->right != nullptr)
				stackNodes.push(pNode->right);
		}

	}
};
