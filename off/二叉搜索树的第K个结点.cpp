//中序遍历
//中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
/********** 递归版本中序遍历 ********/
class Solution {
public:
	//中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot == NULL || k <= 0) return NULL;
		vector<TreeNode*> vec;
		Inorder(pRoot, vec);
		if (k>vec.size())
			return NULL;
		return vec[k - 1];
	}
	//中序遍历，将节点依次压入vector中
	void Inorder(TreeNode* pRoot, vector<TreeNode*>& vec)
	{
		if (pRoot == NULL) return;
		Inorder(pRoot->left, vec);
		vec.push_back(pRoot);
		Inorder(pRoot->right, vec);
	}
};

/********** 非递归版本中序遍历 ********/
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
