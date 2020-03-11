/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正

******************************************************************************************/

#include "LeetCode.h"

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		if (size < 2)
		{
			return 0;
		}
		vector<int> dp(size,0);//数组也可以去掉
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int i = 2; i < size; i++)
		{
			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		}	

		return min(dp[size - 2], dp[size - 1]);
    }
};


class Solution{
public://这个方法为啥会慢
    int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		if (size < 2)
		{
			return 0;
		}

		int dp0 = cost[0];
		int dp1 = cost[1];
		for (int i = 2; i < size; i++)
		{
			int dpi = min(dp0,dp1) + cost[i];
			dp0 = dp1;
			dp1 = dpi;
		}	

		return min(dp0, dp1);
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
        vector<int> cost = stringToIntegerVector(line);
        
        int ret = Solution().minCostClimbingStairs(cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



