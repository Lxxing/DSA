/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
面试题 17.16. 按摩师
******************************************************************************************/
#include "LeetCode.h"

 class Solution {
 public:
 		int massage(vector<int>& nums) {
		if (0 == nums.size())
		{
		    return 0;
		}
 		if (1 == nums.size())
		{
		    return nums[0];
		}
		if (2 == nums.size())
		{
		    return max(nums[0],nums[1]);
		}
		int maxMas = INT_MIN;
 		vector<int> dp(nums.size(),0);
 		dp[0] = nums[0];
 		dp[1] = max(nums[0],nums[1]);
		for (int i = 2; i < nums.size(); ++i)
		{
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		
 		return dp[nums.size() - 1];
 	}
	 int massage1(vector<int>& nums) {
		if (0 == nums.size())
		{
		    return 0;
		}
 		if (1 == nums.size())
		{
		    return nums[0];
		}
		if (2 == nums.size())
		{
		    return max(nums[0],nums[1]);
		}
		int maxMas = INT_MIN;
 		vector<int> dp(nums.size(),0);
 		dp[0] = nums[0];
 		dp[1] = nums[1];//这儿的初始含义有错误才导致后面的依次判断
		for (int i = 2; i < nums.size(); ++i)
		{
			int maxdp = INT_MIN;
			for (int j = 0; j < i - 1; ++j)
			{
				maxdp = max(maxdp,nums[i] + dp[j]);
			}
			dp[i] = max(maxdp,dp[i - 1]);
		}
		
 		return dp[nums.size() - 1];
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
		 
		 int ret = Solution().massage(nums);
 
		 string out = to_string(ret);
		 cout << out << endl;
	 }
	 return 0;
 }





