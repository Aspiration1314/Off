/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
/*分为三步：
1）在旧链表中创建新链表，此时不处理新链表的兄弟节点 ；
2）根据旧链表的兄弟节点，初始化新链表的兄弟节点；
3）从旧链表中拆分得到新链表；*/
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		// step.1 Copy Node
		RandomListNode *pNode = pHead;
		while (pNode != nullptr)
		{
			RandomListNode* pCloned = new RandomListNode(pNode->label);
			pCloned->next = pNode->next;
			// newNode->random = nullptr;

			pNode->next = pCloned;
			pNode = pCloned->next;
		}

		// step.2 Copy random
		pNode = pHead;
		while (pNode != nullptr)
		{
			RandomListNode *pCloned = pNode->next;
			if (pNode->random != nullptr)
				pCloned->random = pNode->random->next;
			pNode = pCloned->next;
		}

		// step.3 Split
		pNode = pHead;
		RandomListNode *pCloneHead, *pCloneNode;

		if (pNode != nullptr)
		{
			pCloneHead = pCloneNode = pHead->next;
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}

		while (pNode != nullptr)
		{
			pCloneNode->next = pNode->next;
			pCloneNode = pCloneNode->next;
			pNode->next = pCloneNode->next;
			pNode = pNode->next;
		}

		return pCloneHead;
	}
};
