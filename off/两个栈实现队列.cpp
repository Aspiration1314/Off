/*思路：stack1:负责压栈，stack2负责弹栈（如果为空，则将stack1中元素压入stack2）；*/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int val = stack1.top();
				stack1.pop();
				stack2.push(val);
			}
		}
		int val = stack2.top();
		stack2.pop();
		return val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

