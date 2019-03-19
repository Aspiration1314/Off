/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
/* 回溯法，终止条件是为叶子节点，且值相等； */
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> pathes;
		if (root == nullptr)
			return pathes;

		vector<int> onePath;
		int curSum = 0;
		findPath(root, pathes, onePath, expectNumber, curSum);

		return pathes;
	}
private:
	void findPath(TreeNode *pRoot, vector<vector<int>> &pathes, vector<int> onePath, int expectNumber, int &curSum)
	{
		curSum += pRoot->val;
		onePath.push_back(pRoot->val);

		bool isLeaf = false;
		if (pRoot->left == nullptr && pRoot->right == nullptr)
			isLeaf = true;
		if (isLeaf && curSum == expectNumber)
		{
			pathes.push_back(onePath);
		}

		if (pRoot->left != nullptr)
			findPath(pRoot->left, pathes, onePath, expectNumber, curSum);
		if (pRoot->right != nullptr)
			findPath(pRoot->right, pathes, onePath, expectNumber, curSum);

		curSum -= pRoot->val;
		onePath.pop_back();
	}
};
