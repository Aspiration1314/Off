/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;   // next 指向父节点；
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
}
};
思路：有两种情况
1.存在右孩子，那么下一个节点就是右孩子的左孩子（的左孩子的左孩子......）
2.不存在右节点，下一个就是是其父节点且满足该父节点是其父节点的左孩子；
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;

		TreeLinkNode* pNext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode* pRight = pNode->right;
			while (pRight->left != nullptr)
				pRight = pRight->left;

			pNext = pRight;
		}
		else if (pNode->next != nullptr)
		{
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;
			while (pParent != nullptr && pCurrent == pParent->right)
			{
				pCurrent = pParent;
				pParent = pParent->next;
			}

			pNext = pParent;
		}

		return pNext;
	}
};
