/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
    	int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.at(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.at(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.at(i) != T.at(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
    }

    bool backspaceCompare1(string S, string T) {
		stack<char> stackS;
		stack<char> stackT;
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == '#')
			{
				if(stackS.size()) stackS.pop();
			}
			else
			{
				stackS.push(S[i]);
			}
		}
		for (int i = 0; i < T.size(); ++i)
		{
			if (T[i] == '#')
			{
				if(stackT.size()) stackT.pop();
			}
			else
			{
				stackT.push(T[i]);
			}
		}

		if (stackS.size() != stackT.size())
		{
			return false;
		}
		else
		{
			
			while(stackS.size())
			{
				if (stackS.top() == stackT.top())
				{
					stackS.pop();
					stackT.pop();
				}
				else
				{
					return false;
				}
			}
			return true;
		}
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
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);
        
        bool ret = Solution().backspaceCompare(S, T);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}


