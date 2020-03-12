/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
//L1����֮�͵�����
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int pHead = 0;
		int pTailer = numbers.size() - 1;
		vector<int> result;
		while (pHead < pTailer)
		{
			if (numbers[pHead] + numbers[pTailer] == target)
			{
				result.push_back(pHead + 1);
				result.push_back(pTailer + 1);
				return result;
			}
			numbers[pHead] + numbers[pTailer] < target ? pHead++ : pTailer--;
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
        vector<int> numbers = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(numbers, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}


