/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> solution;
        for(int i = 0; i < s.size(); i++)
        {
            char item = s[i];
            switch(item)
            {
                case '(':
                case '{':
                case '[':
                    solution.push(item);
                    break;
                case ')':
                {
                	if(solution.empty()) return false;//需要判断单个非法右括号
                    char stackTop = solution.top();
					if (stackTop == '(')
					{
						solution.pop();
					}
					else
					{
						return false;
					}
					break;
				}
                case '}':
                {
                	if(solution.empty()) return false;
                    char stackTop = solution.top();
					if (stackTop == '{')
					{
						solution.pop();
					}
					else
					{
						return false;
					}
					break;
				}
                case ']':
                {
                	if(solution.empty()) return false;
                    char stackTop = solution.top();
					if (stackTop == '[')
					{
						solution.pop();
					}
					else
					{
						return false;
					}
					break;
				}
                default:
                    break;
            }

        }
        return solution.empty();
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		
		bool ret = Solution().isValid(s);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}



