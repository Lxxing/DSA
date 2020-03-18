
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
836. �����ص�
******************************************************************************************/

#include "LeetCode.h"

//�����׶���ͶӰ��
//�ص��������߶ε��ཻ�Ĵ�ͷ�����ཻ��Сͷ
class Solution{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));
    }
};

//�ĸ���λ��Ҳ����ͶӰ���߶γ����Ƶ�������
class Solution2{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
};

//�ٷ���
class Solution1{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		bool xOver = !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] );
		bool yOver = !(rec1[3] <= rec2[1] || rec1[1] >= rec2[3] );
		return xOver && yOver;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> rec1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> rec2 = stringToIntegerVector(line);
        
        bool ret = Solution().isRectangleOverlap(rec1, rec2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

