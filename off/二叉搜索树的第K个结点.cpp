//�������
//��������Ľ�������������У���K��Ԫ�ؾ���vec[K-1]�洢�Ľڵ�ָ�룻
/********** �ݹ�汾������� ********/
class Solution {
public:
	//��������Ľ�������������У���K��Ԫ�ؾ���vec[K-1]�洢�Ľڵ�ָ�룻
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot == NULL || k <= 0) return NULL;
		vector<TreeNode*> vec;
		Inorder(pRoot, vec);
		if (k>vec.size())
			return NULL;
		return vec[k - 1];
	}
	//������������ڵ�����ѹ��vector��
	void Inorder(TreeNode* pRoot, vector<TreeNode*>& vec)
	{
		if (pRoot == NULL) return;
		Inorder(pRoot->left, vec);
		vec.push_back(pRoot);
		Inorder(pRoot->right, vec);
	}
};

/********** �ǵݹ�汾������� ********/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		int count = 0;
		stack<TreeNode*> s;
		TreeNode *p = pRoot;

		while (!s.empty() || p) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else if (!s.empty()) {
				p = s.top();
				s.pop();
				if (++count == k)
					return p;
				p = p->right;
			}
		}
		return nullptr;
	}
};
