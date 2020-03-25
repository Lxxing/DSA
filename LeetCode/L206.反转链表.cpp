/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
83. 删除排序链表中的重复元素
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

ListNode* reverseList(ListNode* head) {
		if (NULL == head || NULL == head->next)//输入检测；递归基
		{
			return head;
		}

    	ListNode *curHead = reverseList(head->next);//递归下一个节点
        head->next->next = head;
    	head->next = NULL;
		return curHead;
    }


/*

在遍历列表时，将当前节点的 next 指针改为指向前一个元素。
由于节点没有引用其上一个节点，因此必须事先存储其前一个元素。
在更改引用之前，还需要另一个指针来存储下一个节点。
不要忘记在最后返回新的头引用！
*/
    ListNode* reverseList1(ListNode* head) {
		ListNode *pTailer = head;
		if (NULL == head)
		{
			return pTailer;
		}

    	ListNode *curHead = head->next;
        ListNode *preHead = curHead;
		while (curHead)
		{
			curHead = curHead->next; 
			preHead->next = pTailer;
			pTailer = preHead;
			preHead = curHead;
		}
		head->next = NULL;
		return pTailer;
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
        
        ListNode* ret = Solution().reverseList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}


