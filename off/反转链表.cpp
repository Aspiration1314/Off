/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
/* ˼·����������ָ�룬�ֱ�ָ��ǰ��㣬ǰһ����㣬��һ����� */
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

