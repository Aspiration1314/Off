/*
�������д���Ҫ��ӡ�Ľ�㣻
��������������
toBePrinted��ʾ��ǰ���л�û�д�ӡ�ĸ�����
nextLevel��ʾ��һ��Ľ������
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
