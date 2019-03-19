/* 辅助栈：模拟整个过程 */
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int length = pushV.size();
		int length2 = popV.size();
		if (length <= 0 || length2 <= 0 || (length != length2))
			return false;

		stack<int> stackV;
		int index_push = 0, index_pop = 0;
		while (index_pop < length)
		{
			while (stackV.empty() || stackV.top() != popV[index_pop])
			{
				if (index_push == length)
					break;
				stackV.push(pushV[index_push++]);
			}
			if (stackV.top() != popV[index_pop])
				break;
			++index_pop;
			stackV.pop();
		}
		if (stackV.empty() && index_pop == length)
			return true;
		else
			return false;
	}
};
