/*
1.定义快慢指针，找到相遇节点；
2.计算环的长度length；
3.在定义快慢指针，先让快指针走length步，在让慢指针走。直到两个指针相等时，即为入口节点；
复杂度为O(n);
*/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode *meetNode = meetingNode(pHead);
		if (meetNode == nullptr)
			return nullptr;

		int loopLength = 1;
		ListNode *pNode1 = meetNode->next;
		while (pNode1 != meetNode)
		{
			++loopLength;
			pNode1 = pNode1->next;
		}
		pNode1 = pHead;
		ListNode *pNode2 = pHead;

		for (int i = 0; i<loopLength; i++)
			pNode1 = pNode1->next;

		while (pNode1 != pNode2)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;

	}

	ListNode* meetingNode(ListNode *pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode *pSlow = pHead->next;
		if (pSlow == nullptr)
			return nullptr;

		ListNode *pFast = pSlow->next;
		while (pFast != nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != nullptr)
				pFast = pFast->next;
		}
		return nullptr;
	}
};
