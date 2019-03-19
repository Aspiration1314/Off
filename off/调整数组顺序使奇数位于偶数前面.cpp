注：相比剑指offer书要难（要保证相对顺序不变）
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int length = array.size();
		if (length == 0 || length == 1)
			return;

		int index_even = 0, index_odd;
		while (index_even<length)
		{
			while (index_even<length && !isEven(array[index_even]))
				++index_even;
			index_odd = index_even + 1;
			while (index_odd<length && isEven(array[index_odd]))
				++index_odd;

			if (index_odd<length)
			{
				int temp = array[index_odd];
				for (int i = index_odd; i>index_even; i--)
					array[i] = array[i - 1];
				array[index_even] = temp;
			}
			else
				break;
		}

	}

	bool isEven(int number){
		if ((number & 0x1) == 0)
			return true;
		return false;
	}

};



/*************方法二 申请空间***********/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int length = array.size();
		if (length == 0 || length == 1)
			return;

		vector<int> res;
		for (int i = 0; i<length; i++)
		{
			if ((array[i] & 0x1) != 0)
				res.push_back(array[i]);
		}

		for (int i = 0; i<length; i++)
		{
			if ((array[i] & 0x1) == 0)
				res.push_back(array[i]);
		}
		array = res;
	}
};

