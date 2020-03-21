/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
338. 比特位计数

******************************************************************************************/

#include "LeetCode.h"
//P(x)=P(x/2)+(x mod 2)
class Solution {
public:
	
    vector<int> countBits(int num) {
	    vector<int> result(num + 1);
		int index = 0;
		while (index <= num)
		{
			result[index] = result[index >> 1] + index % 2;// x % 2 is x & 1
			index++;
		}

	    return result;
    }
};

class Solution1 {
public:
	int counteOnes(int num)
	{
		int result = 0;
		while (num > 0)
		{
			if ((num & 1)== 1)
			{
				result++;
			}
			num >>= 1;
		}

		return result;
	}
    vector<int> countBits(int num) {
	    vector<int> result(num + 1);
		int index = 0;
		while (index <= num)
		{
			result[index] = counteOnes(index);
			index++;
		}

	    return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        vector<int> ret = Solution().countBits(num);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

