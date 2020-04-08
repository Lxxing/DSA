/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
    string removeOuterParentheses(string S) {
		string result = "";
		int startL = 1;
		int startR = 0;
		for (int i = 1; i < S.size(); ++i)
		{
			if (S[i] == '(')
			{
				startL++;
			}
			else
			{
				startR++;
			}
			if (startL != startR)
			{
				result.push_back(S[i] );
			}
			else
			{
				i++;//skip "("
				startL = 1;
				startR = 0;
			}
		}
		return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        string ret = Solution().removeOuterParentheses(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}


