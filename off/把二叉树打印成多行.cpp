/*
借助队列存在要打印的结点；
引入两个变量：
toBePrinted表示当前层中还没有打印的个数；
nextLevel表示下一层的结点数；
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int> > result;
		if (pRoot == nullptr)
			return result;

		std::queue<TreeNode*> nodes;
		nodes.push(pRoot);
		int nextLevel = 0;
		int toBePrinted = 1;
		vector<int> oneRow;
		while (!nodes.empty())
		{
			TreeNode* pNode = nodes.front();
			oneRow.push_back(pNode->val);

			if (pNode->left != nullptr)
			{
				nodes.push(pNode->left);
				++nextLevel;
			}
			if (pNode->right != nullptr)
			{
				nodes.push(pNode->right);
				++nextLevel;
			}

			nodes.pop();
			--toBePrinted;
			if (toBePrinted == 0)
			{
				result.push_back(oneRow);
				oneRow.clear();
				toBePrinted = nextLevel;
				nextLevel = 0;
			}
		}
		return result;
	}
};
