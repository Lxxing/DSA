/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
141. 环形链表
******************************************************************************************/
#include "LeetCode.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (NULL == head)
		{
			return false;
		}
		ListNode* pTailer = head;

		while (head->next)
		{
			head = head->next->next;
			if (NULL == head)
			{
				return false;
			}
			pTailer = pTailer->next;
			if (head == pTailer)
			{
				return true;
			}
		}

		return false;
    }
};
class Solution1 {
public:
    bool hasCycle1(ListNode *head) {
        if (NULL == head)
		{
			return false;
		}
		ListNode* pTailer = head;
		unordered_map<int,int> dp;
		dp[0] = head->val;
		int index = 1;
		while (head->next)
		{
			head = head->next;
			unordered_map<int,int>::iterator p = dp.find(head->val);
			if (p != dp.end())
			{
				return true;
			}
			
			dp[index] = head->val;
			index++;
		}

		return false;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int pos = stringToInteger(line);
        
        bool ret = Solution().hasCycle(head, pos);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}



