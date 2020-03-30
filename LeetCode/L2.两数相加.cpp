
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"

//[5][5]
//[1][9,9]
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyNode(0);
        ListNode* phead = &dummyNode;
        int carry = 0;
		while (l1 && l2)
		{
			int sum = l1->val + l2->val + carry;//最大19，carry不可能为2
			
			phead->next = new ListNode(sum % 10);
			phead = phead->next;

			sum >= 10 ? carry = 1 : carry = 0;

			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1)//这两个可以都合并到while中
		{
			ListNode *head = l1;
			while (head)
			{
				int sum = head->val + carry;
				
				phead->next = new ListNode(sum % 10);
				phead = phead->next;
				
				sum >= 10 ? carry = 1 : carry = 0;
				head = head->next;
			}
		}
		if (l2)
		{
			ListNode *head = l2;
			while (head)
			{
				int sum = head->val + carry;
				
				phead->next = new ListNode(sum % 10);
				phead = phead->next;
				
				sum >= 10 ? carry = 1 : carry = 0;
				head = head->next;
			}
			
		}
		if (carry)
		{
			phead->next = new ListNode(carry);
			phead = phead->next;
		}
		return dummyNode.next;
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

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

