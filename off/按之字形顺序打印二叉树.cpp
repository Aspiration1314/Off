/*
借助两个辅助栈；
在打印某一行节点时，把下一层的子节点保存到相应的栈里。
如果当前打印的是奇数层（一，三层等），则先保存左子结点再保存右子结点到第一个栈里；
如果当前打印的是偶数层（二，四层等），则先保存右子结点再保存左子结点到第二个栈里；
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == nullptr)
			return result;

		stack<TreeNode*> levels[2];
		int current = 0;
		int next = 1;

		levels[current].push(pRoot);
		vector<int> oneRow;
		while (!levels[0].empty() || !levels[1].empty())
		{
			TreeNode *pNode = levels[current].top();
			levels[current].pop();
			oneRow.push_back(pNode->val);

			if (current == 0)
			{
				if (pNode->left != nullptr)
					levels[next].push(pNode->left);
				if (pNode->right != nullptr)
					levels[next].push(pNode->right);
			}
			else
			{
				if (pNode->right != nullptr)
					levels[next].push(pNode->right);
				if (pNode->left != nullptr)
					levels[next].push(pNode->left);
			}
			if (levels[current].empty())
			{
				result.push_back(oneRow);
				oneRow.clear();
				current = 1 - current;
				next = 1 - next;
			}
		}
		return result;
	}
};
