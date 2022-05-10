
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
* 9. ������
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
	//
	bool isPalindrome(int x) {
		if (x < 0 )
		{
			return false;
		}

		long long convertX = 0;
		long long dummyX = x;
		while (dummyX > 0 )
		{
			convertX = convertX * 10 + dummyX % 10;
			dummyX /= 10;
		}

		return convertX == x;
	}

	bool isPalindrome1(int x) {
		//�������.0��β�������ں�����㷨�л��жϴ���
		if (x < 0 || (x % 10 ==0 && x != 0))
		{
			return false;
		}

		//ȫ����ת�������.����һ��convertXλ������dummyXʱ,λ������һ��
		//��������ʹ��long long�洢����
		int convertX = 0;
		int dummyX = x;
		while (dummyX > 0 && dummyX > convertX)
		{
			convertX = convertX * 10 + dummyX % 10;
			dummyX /= 10;
		}

		//
		return convertX == dummyX || convertX == dummyX * 10 + convertX % 10;
	}

    bool isPalindrome0(int x) {
		string result = std::to_string(x);
		string::iterator beginP = result.begin();
		string::iterator endP = result.end() - 1;//endָ���ڱ��սڵ�
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


