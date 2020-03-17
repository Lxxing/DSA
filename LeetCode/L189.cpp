/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
189. 旋转数组
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		k %= size;//当k>size事
		reverse(nums,0,size - 1);
		reverse(nums,0,k - 1);
		reverse(nums,k,size - 1);//std::reverse
    }
    void reverse(vector<int>& nums,  int start, int end)
    {
		while (start < end)
		{
			std::swap(nums[start],nums[end]);
			start++;
			end--;
		}
    }
};

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {

		for (int i = 0; i < k; ++i)
		{
			int item = nums[nums.size() - 1];
			for (int j = nums.size() - 1; j > 0; j--)
			{
				nums[j] = nums[j - 1];
			}
			nums[0] = item;
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
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        Solution().rotate(nums, k);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}



