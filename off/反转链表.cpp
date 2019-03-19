/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
/* 思路：定义三个指针，分别指向当前结点，前一个结点，后一个结点 */
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;
		if (pHead->next == nullptr)
			return pHead;

		ListNode *pPreNode = pHead, *pCurNode = pHead->next, *pNextNode;
		pPreNode->next = nullptr;
		while (pCurNode->next != nullptr)
		{
			pNextNode = pCurNode->next;

			pCurNode->next = pPreNode;
			pPreNode = pCurNode;
			pCurNode = pNextNode;
		}
		pCurNode->next = pPreNode;
		return pCurNode;
	}
};

