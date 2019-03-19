/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/* 思路（递归）：根据前序遍历的第一个数字创建根节点；在中序便利找到根节点的位置；确定左右子树节点数量；递归构建左右子树；*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty() || pre.size() != vin.size())
			return nullptr;

		vector<int> left_pre, right_pre, left_vin, right_vin;
		TreeNode *node = new TreeNode(pre[0]);

		int left_length = 0;
		while (pre[0] != vin[left_length] && left_length < pre.size())
			++left_length;

		for (int i = 0; i<left_length; i++)
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}

		for (int i = left_length + 1; i<pre.size(); i++)
		{
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		node->left = reConstructBinaryTree(left_pre, left_vin);
		node->right = reConstructBinaryTree(right_pre, right_vin);

		return node;
	}
};

