/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
219. �����ظ�Ԫ�� II
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
				dp.insert(std::make_pair(nums[i],i));//�ظ�Ԫ�ز��޸�
			}
			else if( (i - dp[nums[i]]) <= k)//�Ѿ���������������㣬��������������
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



