/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
121. 买卖股票的最佳时机
******************************************************************************************/

#include "LeetCode.h"

class Solution1{
public:
	int maxProfit(vector<int>& prices) {
		int rnt = 0;
		for(int i = 0; i < prices.size(); i++)
			for(int j = i+1; j < prices.size(); j++)
				rnt = max(rnt,prices[j]-prices[i]);
		return rnt;
	}
};
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int rnt = 0;
		int minPrice = INT_MAX;//初始值需要最大
		for(int i = 0; i < prices.size(); i++)
		{
			minPrice = min(minPrice,prices[i]);
			rnt = max(rnt,prices[i]-minPrice);
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


