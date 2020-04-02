/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
//["5","-2","4","C","D","9","+","+"]
    int calPoints(vector<string>& ops) {
		stack<int> dp;
		int result = 0;
		for (int i = 0; i < ops.size(); ++i)
		{
			if("C" == ops[i])
			{
				int num = dp.top();
				dp.pop();
				result -= num;
			}
			else if("D" == ops[i])
			{
				int num = dp.top();
				//leetcode in china not support left shift of negative value
				num *= 2;
				result += (num);
				dp.push(num);
			}
			else if("+" == ops[i])
			{
				int num1 = dp.top();
				dp.pop();
				int num2 = dp.top();
				dp.push(num1);
				dp.push(num1 + num2);
				result += num1 + num2;
			}
			else
			{
				int num = atoi(ops[i].c_str());
				result += num;
				dp.push(num);
			}
		}
		return result;
    }
};


void main()
{
	const char *str1 = "-2";
	isdigit(*str1);
	int num = -2;
	int t = num << 1;
	Solution* obj = new Solution();
	vector<string> ops = { "5","2","C","D","+" };
	obj->calPoints(ops); 
	ops = { "5","-2","4","C","D","9","+","+" };
	obj->calPoints(ops);
}

