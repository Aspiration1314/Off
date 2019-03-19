/*
������������ջ��
�ڴ�ӡĳһ�нڵ�ʱ������һ����ӽڵ㱣�浽��Ӧ��ջ�
�����ǰ��ӡ���������㣨һ������ȣ������ȱ������ӽ���ٱ������ӽ�㵽��һ��ջ�
�����ǰ��ӡ����ż���㣨�����Ĳ�ȣ������ȱ������ӽ���ٱ������ӽ�㵽�ڶ���ջ�
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
