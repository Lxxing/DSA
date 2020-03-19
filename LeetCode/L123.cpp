/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
123. 买卖股票的最佳时机 III
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
		{
			return 0;
		}
		int rnt = 0;
		vector<int> dp(prices.size(),0);
		vector<int> dpRec(prices.size(),0);

		int minprice = prices[0];
		for(int i = 1; i < prices.size(); i++)
		{
			minprice = min(minprice,prices[i]); 
			dp[i] = max(dp[i - 1],prices[i] - minprice);
		}
		int maxprice = prices[prices.size() - 1];
		for(int i = prices.size() - 2; i >= 0 ; i--)
		{
			maxprice = max(maxprice,prices[i]); 
			dpRec[i] = max(dpRec[i + 1],maxprice - prices[i]);
			//亏本最大dpRec[i] = min(dpRec[i + 1],prices[i] -maxprice );
			
		}
		
		for(int i = 1; i < dp.size(); i++)
		{
			rnt = max(rnt,dp[i] + dpRec[i]);
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




