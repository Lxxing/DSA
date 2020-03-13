/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
7. 整数反转
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x!=0)
        {
           result = result*10+x%10;   
           x = x/10;    
        }
        if((int)result == result)//浮点与整数互转判断
        {
            return (int) result;
        }
        else
        {
            return 0;
        }
    }
};
//1534236469
//-2147483648
class Solution1 {
public:
    int reverse(int x) {
		queue<int> S;
		int flag = x > 0 ? true : false;
		if (INT_MIN == x)
		{
			return 0;
		}
		int num = abs(x);
		while (num > 0)
		{
			int div = num % 10;
			S.push(div);
			num /= 10;
		}
		
		double result = 0;
		while (!S.empty())
		{
			result = result * 10 + S.front();
			S.pop();
			if (result > INT_MAX)
			{
				return 0;
			}
		}
		return flag ? result : -result;
    }
};



int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
