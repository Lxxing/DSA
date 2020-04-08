/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"
class Solution {
public:
    string removeDuplicates(string S) {
		
		string::iterator begin = S.begin();
		string::iterator end = S.end();
		string::iterator pCur = begin;

		while (begin != end)
		{
			if (pCur == S.begin() || *begin != *(pCur - 1))
			{
				*pCur = *begin;
				pCur++;
			}
			else
			{
				pCur--;
			}
			begin++;
		}

		return S.substr(0,pCur - S.begin());
    }

    string removeDuplicates1(string S) {
		string result = "";
		
		string::iterator begin = S.begin();
		string::iterator end = S.end();

		while (begin != end)
		{
			if (result.empty() || *begin != result.back())
			{
				result.push_back(*begin);
			}
			else
			{
				result.pop_back();
			}
			begin++;
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
        
        string ret = Solution().removeDuplicates(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}


