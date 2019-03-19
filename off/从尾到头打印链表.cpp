/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
// 思路：借助辅助栈，或者使用递归；
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> reverse_list;
		stack<int> nodes;

		ListNode *p_node = head;
		while (p_node != nullptr)
		{
			nodes.push(p_node->val);
			p_node = p_node->next;
		}

		int tempVal;
		while (!nodes.empty())
		{
			tempVal = nodes.top();
			reverse_list.push_back(tempVal);
			nodes.pop();
		}
		return reverse_list;
	}
};
