/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
// 定义快慢指针，快的先走K步；
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode *pAhead = pListHead;
		ListNode *pAfter = pListHead;

		for (int i = 0; i<k - 1; i++)
		{
			if (pAhead->next != nullptr)
				pAhead = pAhead->next;
			else
				return nullptr;
		}

		while (pAhead->next != nullptr)
		{
			pAhead = pAhead->next;
			pAfter = pAfter->next;
		}

		return pAfter;

	}
};

