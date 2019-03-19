
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
/*思路：统计两个链表的长度，计算差值k，定义快慢指针，长链表先走k步*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;

		int length1 = getListLength(pHead1);
		int length2 = getListLength(pHead2);
		ListNode *pAhead = pHead1;
		ListNode *pBehind = pHead2;
		int diff = length1 - length2;
		if (length1 < length2)
		{
			pAhead = pHead2;
			pBehind = pHead1;
			diff = length2 - length1;
		}

		for (int i = 0; i<diff; i++)
			pAhead = pAhead->next;

		while (pAhead != nullptr && pBehind != nullptr)
		{
			if (pAhead == pBehind)
				return pAhead;
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}

		return nullptr;
	}

private:
	int getListLength(ListNode *pHead)
	{
		if (pHead == nullptr)
			return 0;
		int length = 0;
		while (pHead != nullptr)
		{
			++length;
			pHead = pHead->next;
		}
		return length;
	}

};
