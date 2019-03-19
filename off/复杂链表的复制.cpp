/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
/*��Ϊ������
1���ھ������д�����������ʱ��������������ֵܽڵ� ��
2�����ݾ�������ֵܽڵ㣬��ʼ����������ֵܽڵ㣻
3���Ӿ������в�ֵõ�������*/
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
