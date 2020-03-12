/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
118. 杨辉三角
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> rnt;
		rnt.resize(numRows);
		if (0 == numRows)
		{
			return rnt;
		}

		rnt[0].resize(1);
		rnt[0][0] = 1;

		for (int i = 2; i < numRows + 1; ++i)
		{
			rnt[i - 1].resize(i);
			rnt[i - 1][0] = 1;
			int j = 1;
			for (; j < i - 1; ++j)
			{
				rnt[i - 1][j] = (rnt[i - 2][j] + rnt[i - 2][j - 1]);
			}
			rnt[i - 1][j] = 1;
		}
		return rnt;
    }
};


int main() {
	int nums = 5;
	vector<vector<int>> rnt= Solution().generate(nums);
	for (int i = 0; i < rnt.size(); ++i)
	{
		vector<int> item = rnt[i];
		for (int j = 0; j < item.size(); ++j)
		{
			std::cout << item[j] << ",";
		}
		std::cout << std::endl;
	}
	return 0;
}


