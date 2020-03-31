
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size());
		return nums;
    }

    void mergeSort(vector<int>& nums,int lo, int hi){
		if ( hi - lo <= 1)
		{
			return;
		}

		int mid = (lo + hi) >> 1;
        mergeSort(nums,lo,mid);
        mergeSort(nums,mid,hi);
        mergeArray(nums,lo,mid,hi);
    }
    void mergeArray(vector<int>& nums,int lo, int mid,int hi){
    	int lenLo = mid - lo;
		int lenHi = hi;
		vector<int> dummy(lenLo);
		memcpy(&dummy[0],&nums[lo],sizeof(int) * lenLo);
		int pLo = 0;
		int pHi = mid;
		int pCur = lo;
		while (pLo < lenLo || pHi < lenHi)
		{
			if (((pHi < lenHi) && pLo >= lenLo) || 
				((pHi < lenHi) && dummy[pLo] > nums[pHi]) )
			{
				nums[pCur++] = nums[pHi++];
			}
			if ( ((pLo < lenLo) && pHi >= lenHi) || 
				((pLo < lenLo) && dummy[pLo] <= nums[pHi]) )
			{
				nums[pCur++] = dummy[pLo++];
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
        
        vector<int> ret = Solution().sortArray(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

