/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
234. 回文链表
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (NULL == head || NULL == head->next)
		{
			return true;//空或者单个属于回文
		}

		ListNode * fast = head;
		ListNode * slow = head;
		while (fast && fast->next)//可能跨过空
		{
			slow = slow->next;
			fast = fast->next->next;
		}


		ListNode * curHead = slow;
		ListNode * curEnd = slow;
		slow = slow->next;
		while (slow)
		{
			ListNode *preHead = slow;
			slow = slow->next;
			preHead->next = curHead;
			curHead = preHead;			
		}
		curEnd->next = NULL;

		while (curHead && head)
		{
			if (curHead->val != head->val)
			{
				return false;
			}
			curHead = curHead->next;
			head = head->next;
		}

		return true;
		
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}






