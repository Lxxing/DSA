/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
122. 买卖股票的最佳时机 II
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int rnt = 0;
		vector<int> dp(prices.size(),0);//可优化掉，利用原始数组，用整数记录i前一个值
		for(int i = 1; i < prices.size(); i++)
		{
			if (prices[i] - prices[i - 1] > 0)
			{
				if (dp[i - 1] > 0)
				{
					dp[i] = dp[i - 1];
					dp[i - 1] = 0;
				}
				dp[i] += (prices[i] - prices[i - 1]);
			}
		}
		for(int i = 1; i < dp.size(); i++)
		{
			if(dp[i] > 0) rnt += dp[i];
		}

		return rnt;
	}
};
//lamda表达式
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
//[7,6,4,3,1]
//[7,1,5,3,6,4]
	string line;
	while (getline(cin, line)) {
		vector<int> prices = stringToIntegerVector(line);
		
		int ret = Solution().maxProfit(prices);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}



