/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
414. 第三大的数
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    	if (nums.size() == 0)
		{
			return INT_MIN;
		}
    	if (nums.size() == 1)
		{
			return nums[0];
		}
		if (nums.size() == 2)
		{
			return max(nums[0],nums[1]);
		}
		long max1 = LONG_MIN;
		long max2 = LONG_MIN;
		long max3 = LONG_MIN;//用long来解决int相等的可能

		for (int i = 0; i < nums.size(); ++i)
		{
			//等号为了重复计算，放置重复数字造成技计数错误
			if (nums[i] >= max3)
			{
				if(nums[i] != max3)
				{
					max1 = max2;
					max2 = max3;
				}
				max3 = nums[i];
			}
			else if(nums[i] >= max2)
			{
				if(nums[i] != max2)
				{
					max1 = max2;
				}
				max2 = nums[i];
			}
			else if(nums[i] >= max1)
			{
				max1 = nums[i];
			}
		}
		return max1 == LONG_MIN ? max(max3,max2) : (int)max1;
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
//[1,1,2]
//[1,2,-2147483648]
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().thirdMax(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

