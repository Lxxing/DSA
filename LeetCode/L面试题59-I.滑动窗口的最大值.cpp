/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			vector<int> result;
			if (nums.size() < 1)
			{
				return result;
			}
			result.resize(nums.size() - k + 1);//大小边界
			for (int i = 0; i < nums.size() - 1; ++i)
			{
				int maxNum = nums[i];
				for (int j = 1; j < k; ++j)
				{
					maxNum = max(maxNum,nums[i + j]);//判断初始值
				}
				result[i] = maxNum;
			}
			return result;
		}

    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		vector<int> result;
		if (nums.size() < 1)
		{
			return result;
		}
		result.resize(nums.size() - k + 1);//大小边界
		for (int i = 0; i < nums.size() - k + 1; ++i)
		{
			int maxNum = nums[i];
			for (int j = 1; j < k; ++j)
			{
				maxNum = max(maxNum,nums[i + j]);//判断初始值
			}
			result[i] = maxNum;
		}
		return result;
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().maxSlidingWindow(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

