/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#include "LeetCode.h"

/**************************
  result����֮ǰ������ֵ isNavigate���ţ� d��ʾ��ǰ��
  �����result > 214748364 ʱ ���������һ������� ��res > INT_MAX/10 ʱ���
  ��result = 214748364    ��res == INT_MAX/10 
  ��������� ����ʱ�ӵ���d>=7 �������� d>=7 ����� 
   ���ڸ��� ����ʱ�ӵ���d>=8 ��Ḻ���   ��d>=8 �����
****************************************/
class Automaton {
public:
		void Get(char item)
		{
			state = table[state][GetColum(item)];
			if (isFlow)
			{
				return;
			}
			if ("number" == state)
			{
				int intdata = item - '0';
				if (INT_MAX/10 < result)
				{
					if (isNavigate == true) {
						result = INT_MAX;
					}
					else {
						result = INT_MIN;
					}
					isFlow = true;
					return;
				}
				if (INT_MAX/10 == result)
				{
					if (isNavigate == true && intdata > 7) {
						result = INT_MAX;
					}
					if (isNavigate == false && intdata > 8) {
						result = INT_MIN;
					}
					isFlow = true;
					return;
				}
				result = result * 10 + item - '0';
			}
			else if (state == "signed")
				isNavigate = item == '+' ? true : false;
		}

		int GetResult()
		{
			return isNavigate ? result : -result;
		}

	private:
		int GetColum(char item)
		{
			if (isspace(item))
			{
				return 0;
			}
			if (item == '+' || item == '-')
			{
				return 1;
			}
			if (isdigit(item))
			{
				return 2;
			}
			return 3;
		}

		bool isNavigate = true;
		bool isFlow = false;
		int result = 0;
		string state = "start";
		unordered_map<string, vector<string>> table =
		{				//' '		+/-	      number	other
			{ "start",{ "start", "signed", "number", "end" } },
			{ "signed",{ "end", "end", "number", "end" } },
			{ "number",{ "end", "end", "number", "end" } },
			{ "end",{ "end", "end", "end", "end" } }
		};
	};

class Solution {
public:
    int myAtoi1(string str) {
        string::iterator begin = str.begin();
        string::iterator end = str.end();
		while (begin != end && *begin == ' ' )
		{
			begin++;
		}

		if ( *begin == '+' || *begin == '-' ||
			isdigit(*begin) )
		{
			bool isNavigate = false;
			if (*begin == '-')
			{
				isNavigate = true;
				begin++;
			}
			else if (*begin == '+')
			{
				isNavigate = false;
				begin++;
			}
			
			stack<int> dp;
			while (begin != end && (*begin >= 48 && *begin <= 57))//��Χ����
			{
				if (dp.empty() && *begin == 48)
				{
					begin++;
				}
				else
				{
					dp.push(*begin - 48);
					begin++;
				}
			
			}
			signed long long result = 0;
			signed long long base = 1;//����Ҳ���ܲ�����
			while (dp.size())
			{
				int item = dp.top();
				dp.pop();
				result += item * base;
				base *= 10;
				if (base > 100000000000)
				{
					if(isNavigate == true)
					{
						return INT_MIN;
					}
					else
					{
						return INT_MAX;
					}
				}
			}
			
			result = isNavigate ? -result : result;
			if (result < INT_MIN)
			{
				return INT_MIN;
			}
			if (result > INT_MAX)
			{
				return INT_MAX;
			}

			return result;
		}
		else
		{
			return 0;
		}
		
    }
	
public:
    int myAtoi(string str) {
        Automaton automation;
		string::iterator begin = str.begin();
        string::iterator end = str.end();
		while (begin != end)
		{
			automation.Get(*begin);
			begin++;
		}
		return automation.GetResult();
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
//"  0000000000012345678"
//"-+1"
//"20000000000000000000"
int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

