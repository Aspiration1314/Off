/* ��������ջ������ÿ��ѹջ֮�����Сֵ */
class Solution {
public:
	void push(int value) {
		if (s_data.empty()){
			s_data.push(value);
			s_min.push(value);
		}
		else{
			s_min.push(value<s_min.top() ? value : s_min.top());
			s_data.push(value);
		}s
	}
	void pop() {
		s_data.pop();
		s_min.pop();
	}
	int top() {
		return s_data.top();
	}
	int min() {
		return s_min.top();
	}
private:
	stack<int> s_data;
	stack<int> s_min;
};
