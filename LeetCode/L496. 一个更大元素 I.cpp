
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
				vector<int> result(nums1.size(),-1);
				unordered_map<int,int> dp;
				stack<int> stack;
				
				for (int j = 0; j < nums2.size(); ++j)
				{	
					if (stack.empty())
					{
						stack.push(nums2[j]);
						continue;
					}
					while (!stack.empty() && nums2[j] > stack.top())
					{
						dp.insert(std::make_pair(stack.top(),nums2[j]));
						stack.pop();
					}

					stack.push(nums2[j]);
					
				}

				for (int i = 0; i < nums1.size(); ++i)
				{
					if (dp.count(nums1[i]))
					{
						result[i] = dp[nums1[i]];
					}		
				}
				return result;
		}

    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result(nums1.size(),-1);
			for (int i = 0; i < nums1.size(); ++i)
			{
				int item = nums1[i];
				bool isFind = false;
				for (int j = 0; j < nums2.size(); ++j)
				{	
					if (item == nums2[j])
					{
						isFind = true;
					}
					if (isFind && nums2[j] > item)
					{
						result[i] = nums2[j];
						break;
					}
				}
			}
			return result;
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        vector<int> ret = Solution().nextGreaterElement(nums1, nums2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}


