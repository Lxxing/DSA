/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
53. 最大子序和
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int size = nums.size();
		int dp0 = nums[0];
		int rnt = dp0;
		for (int i = 1; i < size; i++)
		{
			dp0 = max(dp0 + nums[i],nums[i]);
			rnt = max(dp0,rnt);
		}	

		return rnt;
    }
    
};
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
		int size = nums.size();
    	vector<int> dp(nums.size(),0);
    	dp[0] = nums[0];
		int rnt = dp[0];
		for (int i = 1; i < size; i++)
		{
			dp[i] = max(dp[i - 1] + nums[i],nums[i]);
			rnt = max(dp[i], rnt);
		}	

		return rnt;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().maxSubArray(nums);
		ret = Solution1().maxSubArray(nums);
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

