/*
����ĸ��Ӷȣ�O(logn), �õ���λ���ĸ��Ӷ�:O(1)
����˼·��
1.ά��һ���󶥶ѣ�һ��С���ѣ��ұ�֤���㣺
1��С�������ȫ���� �󶥶���ģ�
2��2���Ѹ����Ĳ�ֵС�ڵ���1
2.��insert�����ָ���Ϊ����ʱ��ʹС���Ѹ����ȴ󶥶Ѷ�1��
��insert�����ָ���Ϊż��ʱ��ʹ�󶥶Ѹ�����С���Ѹ���һ����
3.��ô�������ָ���Ϊ����ʱ����λ������С���Ѷ�ͷ��
�������ָ���Ϊż��ʱ������������ 2���Ѷ�ͷƽ����
*/
class Solution {
public:
	void Insert(int num)
	{
		count += 1;
		// Ԫ�ظ�����ż��ʱ,��С���ѶѶ�����󶥶�
		if (count % 2 == 0){
			big_heap.push(num);
			small_heap.push(big_heap.top());
			big_heap.pop();
		}
		else{
			small_heap.push(num);
			big_heap.push(small_heap.top());
			small_heap.pop();
		}
	}
	double GetMedian()
	{
		if (count & 0x1){
			return big_heap.top();
		}
		else{
			return double((small_heap.top() + big_heap.top()) / 2.0);
		}
	}
private:
	int count = 0;
	priority_queue<int, vector<int>, less<int>> big_heap;        // ���һ���󶥶�
	priority_queue<int, vector<int>, greater<int>> small_heap;   // �ұ�һ��С����
	// �󶥶�����Ԫ�ؾ�С�ڵ���С���ѵ�����Ԫ��.
};
