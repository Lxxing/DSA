/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
219. 存在重复元素 II
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
     bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int,int> dp;
		for (int i = 0; i < nums.size(); ++i)
		{
			unordered_map<int,int>::iterator itor = dp.find(nums[i]);
			if (itor == dp.end())
			{
				dp.insert(std::make_pair(nums[i],i));//重复元素不修改
			}
			else if( (i - dp[nums[i]]) <= k)//已经搜索过如果不满足，更不会满足后面的
			{
				return true;
			}
			else
			{
				dp[nums[i]] = i;
			}
		}
		return false;
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
	 
	 string boolToString(bool input) {
		 return input ? "True" : "False";
	 }
	 
	 int main() {
		 string line;
		 while (getline(cin, line)) {
			 vector<int> nums = stringToIntegerVector(line);
			 getline(cin, line);
			 int k = stringToInteger(line);
			 
			 bool ret = Solution().containsNearbyDuplicate(nums, k);
	 
			 string out = boolToString(ret);
			 cout << out << endl;
		 }
		 return 0;
	 }



