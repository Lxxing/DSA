/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
26. 删除排序数组中的重复项
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
		if (length < 2)
		{
			return length;
		}
		int duplicate = 0;
        int head = 0;
        int tailer = 1;
		for ( ;tailer < length;)
		{
			if (nums[head] == nums[tailer])
			{
				 tailer++;//相同数据尾指针走
				 duplicate++;
			}
			else
			{
				head++;//头指针的位置数据不能赋值，需要到新数据的位置
			    nums[head] = nums[tailer++];//赋值两个指针都要走
			}
		}
		return length - duplicate;
    }
};



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}



