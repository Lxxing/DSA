/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
365. 水壶问题
******************************************************************************************/

#include "LeetCode.h"
//贝祖定理
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        
		if (x + y < z) return false;
			if (x == 0 || y == 0) return z == 0 || x + y == z;
			return z % gcd(x, y) == 0;

		return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        getline(cin, line);
        int z = stringToInteger(line);
        
        bool ret = Solution().canMeasureWater(x, y, z);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}


