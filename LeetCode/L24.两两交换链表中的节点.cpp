
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next)
		{
			return head;
		}
		ListNode* result = head;
		ListNode dummyNode(0);
		ListNode*pNode = &dummyNode;
		while (head && head->next)
		{
			ListNode*gHead = head;
			ListNode*pHead = head->next;
			head = head->next->next;
			pHead->next = gHead;
			gHead->next = head;
			
			pNode->next = pHead;//前向连接
			
			pNode = gHead;
			
		}
		return dummyNode.next;
    }

    ListNode* swapPairs1(ListNode* head) {
        if(head == NULL || head->next == NULL)  
        	return head; //终止条件
        ListNode* node = head->next; 
        head->next = swapPairs(head->next->next);
        node->next = head;
        return node;
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
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().swapPairs(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}


