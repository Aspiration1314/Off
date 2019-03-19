/********** µÝ¹é°æ±¾ **********/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);

		return left >= right ? (left + 1) : (right + 1);
	}
};

/********** Ñ­»·°æ±¾ **********/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		queue<TreeNode*> q;
		if (!pRoot)
			return 0;
		q.push(pRoot);
		int level = 0;
		while (!q.empty())
		{
			int len = q.size();
			level++;
			while (len--)
			{
				TreeNode *tmp = q.front();
				q.pop();
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
		}
		return level;
	}
};
