/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
思路：递归判断：R1->left与R2->right比较，R2->left与R1->right比较；
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
private:
	bool isSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right)
			&& isSymmetrical(pRoot1->right, pRoot2->left);
	}
};
