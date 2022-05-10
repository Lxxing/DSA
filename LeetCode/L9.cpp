
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
* 9. 回文数
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    bool isPalindrome(int x) {
		string result = std::to_string(x);
		string::iterator beginP = result.begin();
		string::iterator endP = result.end() - 1;
		int count = 0;
		while (beginP < endP && *beginP == *endP)
		{
			beginP++;
			endP--;
			count++;
		}
		return count < result.length() / 2 ? false : true;
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
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}


