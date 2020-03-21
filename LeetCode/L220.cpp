/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
219. 存在重复元素 III
******************************************************************************************/

#include "LeetCode.h"


class Solution {
public:
	//可能nums[i]为负数，所以负数要向下移动一位
	long getBuckId(int x, int w)
	{
		if(w == 0) return x;
		return x < 0 ? (x/w - 1) : x/w;
	}

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(t < 0 || k < 0 || nums.empty()) return false;
    	unordered_map<long,long> dp;//
        long mod = t + 1L;//可能溢出
		for (int i = 0; i < nums.size(); ++i)
		{
			long buckId = getBuckId(nums[i], t);
			if(dp.count(buckId))
			{
				return true;
			}
            else 
            {
            	dp[buckId] = nums[i];
            }
            
            if(dp.count(buckId - 1))
            {
                if(abs(long(dp[buckId - 1]) - (long)(nums[i])) <= t) 
                	return true;

            }
            if(dp.count(buckId + 1))
            {
                if(abs((long)(dp[buckId + 1])- (long)nums[i]) <= t)
                	return true;
            }
            if(dp.size() > k) 
            	dp.erase(getBuckId(nums[i-k],t));
			
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
//[2,1] , 1,1
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int t = stringToInteger(line);
        
        bool ret = Solution().containsNearbyAlmostDuplicate(nums, k, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}


