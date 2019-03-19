/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
/* 思路：辅助队列 */
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root){
		vector<int> result;
		if (root == nullptr)
			return result;

		queue<TreeNode *> nodes;
		nodes.push(root);
		while (!nodes.empty())
		{
			TreeNode *pNode = nodes.front();
			result.push_back(pNode->val);

			if (pNode->left != nullptr)
				nodes.push(pNode->left);
			if (pNode->right != nullptr)
				nodes.push(pNode->right);

			nodes.pop();
		}

		return result;
	}
};
