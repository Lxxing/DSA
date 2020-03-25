/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
83. ɾ�����������е��ظ�Ԫ��
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
		if (NULL == head || NULL == head->next)//�����⣻�ݹ��
		{
			return head;
		}

    	ListNode *curHead = reverseList(head->next);//�ݹ���һ���ڵ�
        head->next->next = head;
    	head->next = NULL;
		return curHead;
    }


/*

�ڱ����б�ʱ������ǰ�ڵ�� next ָ���Ϊָ��ǰһ��Ԫ�ء�
���ڽڵ�û����������һ���ڵ㣬��˱������ȴ洢��ǰһ��Ԫ�ء�
�ڸ�������֮ǰ������Ҫ��һ��ָ�����洢��һ���ڵ㡣
��Ҫ��������󷵻��µ�ͷ���ã�
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


