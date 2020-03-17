/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
面试题 01.06. 字符串压缩
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    string compressString(string S) {
		string result;
		char pHead = S[0];
		string::iterator pTailer = S.begin() ;
		int sameCount = 0;
		while (pTailer != S.end())
		{
			if (pHead != *pTailer)
			{
				result.push_back(pHead);
				result += to_string(sameCount);
				
				sameCount = 1;
				pHead = *pTailer;//需要移动到不同的字母处
				pTailer++;
			}
			else
			{
				pTailer++;
				sameCount++;
			}
		}

		result.push_back(pHead);
		result += to_string(sameCount);

		return result.size() >= S.size() ? S : result;
    }
};

class Solution1 {
public:
    string compressString(string S) {
		string result;
		string::iterator pHead = S.begin();
		string::iterator pTailer = pHead;
		int sameCount = 0;
		while (pTailer != S.end())
		{
			if (*pHead != *pTailer)
			{
				result.push_back(*pHead);
				result += to_string(sameCount);
				
				sameCount = 1;
				pHead = pTailer;//需要移动到不同的字母处
				pTailer++;
			}
			else
			{
				pTailer++;
				sameCount++;
			}
		}

		result.push_back(*pHead);
		result += to_string(sameCount);
		//若“压缩”后的字符串没有变短，则返回原先的字符串
		return result.size() >= S.size() ? S : result;
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
        
        string ret = Solution().compressString(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}


