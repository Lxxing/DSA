/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
300. 最长上升子序列
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int len = nums.size();
    	vector<int> dp(len,1);
    	
		for (int i = 1; i < len; ++i)
		{
			int dpMax = 1;
			for (int j = 0; j < i; ++j)//必须遍历，不能直接max
			{
				if (nums[j] < nums[i])
				{
					dpMax = max(dpMax,dp[j] + 1);
				}
			}
			dp[i] = dpMax;
		}
		vector<int>::iterator result = std::max_element(dp.begin(), dp.end());
		return result == dp.end() ? 0 : *result;
    }
};


int main() {

    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums);
	vector<int> num0;
	num0.resize(0);
	cout << Solution().lengthOfLIS(num0);
    return 0;
}


