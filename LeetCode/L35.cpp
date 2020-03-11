/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
35. 搜索插入位置
******************************************************************************************/

#include "LeetCode.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int length = nums.size();
		if (length < 1)
		{
			return length;
		}
		
		return BinarySearch(nums.data(),0,length,target);
    }
private:
	int BinarySearch(int *A,int lo,int hi,int tgt)
	{
        int mid = (lo + hi) >> 1;
		for ( ;lo < hi;)
		{
			if (tgt == A[mid])
			{
				 return mid;
			}
			else if (tgt < A[mid])
			{
				hi = mid;//[lo,mid)
			}
			else
			{
				lo = mid + 1;//(mid,hi)
			}
            mid = (lo + hi) >> 1;
		}
        return mid;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		int ret = Solution().searchInsert(nums, target);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
