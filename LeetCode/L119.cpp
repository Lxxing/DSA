/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
118. 杨辉三角2
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<vector<int>> rnt;
		rnt.resize(rowIndex + 1);

		rnt[0].resize(1);
		rnt[0][0] = 1;
		if (0 == rowIndex)
		{
			return rnt[0];
		}

		for (int i = 2; i <= rowIndex + 1; ++i)
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
		return rnt[rowIndex];
    }

    vector<int> getRow1(int rowIndex) {
        vector<int> result;
        for(int i = 0; i <= rowIndex; ++i){
            result.push_back(1);
            for(int j = i - 1; j > 0; --j){
                result[j] += result[j - 1];
            }
        }
        return result;
    }

作者：heromapwrd
链接：https://leetcode-cn.com/problems/pascals-triangle-ii/solution/c-8xing-dai-ma-jian-ji-yi-dong-by-heroma-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

};


int main() {
	int nums = 5;
	vector<int> rnt= Solution().getRow(nums);
	for (int i = 0; i < rnt.size(); ++i)
	{
		std::cout << rnt[i] << ",";
	}
	return 0;
}



