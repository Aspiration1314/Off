/*
插入的复杂度：O(logn), 得到中位数的复杂度:O(1)
核心思路：
1.维护一个大顶堆，一个小顶堆，且保证两点：
1）小顶堆里的全大于 大顶堆里的；
2）2个堆个数的差值小于等于1
2.当insert的数字个数为奇数时：使小顶堆个数比大顶堆多1；
当insert的数字个数为偶数时，使大顶堆个数跟小顶堆个数一样。
3.那么当总数字个数为奇数时，中位数就是小顶堆堆头；
当总数字个数为偶数时，中卫数就是 2个堆堆头平均数
*/
class Solution {
public:
	void Insert(int num)
	{
		count += 1;
		// 元素个数是偶数时,将小顶堆堆顶放入大顶堆
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
	priority_queue<int, vector<int>, less<int>> big_heap;        // 左边一个大顶堆
	priority_queue<int, vector<int>, greater<int>> small_heap;   // 右边一个小顶堆
	// 大顶堆所有元素均小于等于小顶堆的所有元素.
};
