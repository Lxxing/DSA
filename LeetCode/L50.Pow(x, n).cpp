/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"


class Solution {
public:
    double myPow(double x, int n) {
    	double result = 1.0;
    	bool flag = n > 0 ? true : false;
    	int power = abs(n);
    	double powerNumber = x;
		while (power--)
		{
			if (power && 1 == 0)
			{
				powerNumber 

				
			}
			result *= x;
		}
		
		return flag ? result : 1/result;
    }

    double myPow1(double x, int n) {
    	double result = 1.0;
    	bool flag = n > 0 ? true : false;
    	int power = abs(n);
		while (power--)
		{
			result *= x;
		}
		
		return flag ? result : 1/result;
    }
};


int main() {

    double a = Solution().myPow(2.0,10);
	double b = Solution().myPow(2.10000, 3);
	double c = Solution().myPow(2.0, -2);
    return 0;
}


