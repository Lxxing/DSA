/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
88. 合并两个有序数组

******************************************************************************************/

/*太细致可合并
if ((pHead2 == n && pHead < m)
{
	nums1[pHead1++] = nums[pHead++];
}
if ((pHead < m && nums[pHead] <= nums2[pHead2]) ||
    (pHead2 < n && nums[pHead] <= nums2[pHead2]) )
{
	nums1[pHead1++] = nums[pHead++];
}
*/
#include "LeetCode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		if (n == 0)
		{
			return;//[1],1,[],0
		}

		vector<int> nums(nums1);
		int pHead = 0;
		int pHead2 = 0;
		int pHead1 = 0;
		while (pHead < m || pHead2 < n)
		{
			//左右分别遍历,右边界的判断在前
			if ((pHead < m && pHead2 >= n) ||
			    (pHead < m && nums[pHead] <= nums2[pHead2]) )
			{
				nums1[pHead1++] = nums[pHead++];
			}
			if ((pHead2 < n && pHead >= m)||
				(pHead2 < n && nums[pHead] >= nums2[pHead2]) )
			{
				nums1[pHead1++] = nums2[pHead2++];
			}
		}
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
//[2,0] 1 [1] 1
//[2,0] 1 [1] 1

    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        Solution().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}

