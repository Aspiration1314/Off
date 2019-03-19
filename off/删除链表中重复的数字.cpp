/************* 不保留重复节点版本 *****************/
// 1 2 2 3 4 4 5
// 1 3 5

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode *pCurNode = pHead;
		ListNode *pPreNode = nullptr;

		while (pCurNode != nullptr)
		{
			ListNode *pNext = pCurNode->next;
			bool toBeDeleted = false;
			if (pNext != nullptr && pCurNode->val == pNext->val)
				toBeDeleted = true;
			if (!toBeDeleted)
			{
				pPreNode = pCurNode;
				pCurNode = pCurNode->next;
			}
			else
			{
				int value = pCurNode->val;
				ListNode *delNode = pCurNode;
				while (delNode != nullptr && delNode->val == value)
				{
					pNext = delNode->next;
					delete delNode;
					delNode = pNext;
				}
				if (pPreNode == nullptr)
					pHead = pNext;
				else
					pPreNode->next = pNext;
				pCurNode = pNext;
			}
		}
		return pHead;
	}
};


/************* 保留重复节点版本 *****************/
// 1 2 2 3 4 4 5
// 1 2 3 4 5
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode *pCurNode = pHead;
		while (pCurNode != nullptr)
		{
			ListNode *pNext = pCurNode->next;
			if (pNext != nullptr && pCurNode->val == pNext->val)
			{
				int value = pCurNode->val;
				ListNode *delNode = pNext;
				while (delNode != nullptr && delNode->val == value)
				{
					pNext = delNode->next;
					delete delNode;
					delNode = pNext;
				}
				pCurNode->next = pNext;
				pCurNode = pCurNode->next;
			}
			else
				pCurNode = pCurNode->next;
		}
		return pHead;
	}
};
