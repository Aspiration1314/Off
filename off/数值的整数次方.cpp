/*思路 需要考虑以下几种情况
1) base的正负；
2) base是否等于0；
3) exponent的正负；
4) exponent是否为1；*/

class Solution {
public:
	double Power(double base, int exponent) {
		if (base>-0.0000001 && base<0.0000001 && exponent<0)
			return 0.0;

		double result = 1.0;

		unsigned int abs_exponent = (unsigned int)exponent;
		if (exponent < 0)
			abs_exponent = (unsigned int)(-exponent);

		/*
		for(int i=0; i<abs_exponent; i++)
		result = result * base;
		*/
		//
		if (abs_exponent == 0)
			return 1.0;
		if (abs_exponent == 1)
			return base;

		result = base;
		abs_exponent = abs_exponent >> 1;
		while (abs_exponent)
		{
			result *= result;
			abs_exponent = abs_exponent >> 1;
		}
		if (exponent & 0x1 == 1)
			result *= base;
		//
		if (exponent < 0 && result > 0.0)
			result = 1.0 / result;
		return result;
	}
};

