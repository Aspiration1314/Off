/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

/*------------------------------方法一 递归版本--------------------------*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		else if (pHead2 == nullptr)
			return pHead1;

		ListNode *pMerge;
		if (pHead1->val <= pHead2->val)
		{
			pMerge = pHead1;
			pHead1->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			pMerge = pHead2;
			pHead2->next = Merge(pHead1, pHead2->next);
		}
		return pMerge;
	}
};
