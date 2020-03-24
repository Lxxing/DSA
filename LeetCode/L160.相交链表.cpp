
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
160. 相交链表
******************************************************************************************/
#include "LeetCode.h"
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (NULL == headA || NULL == headB)
			{
				return NULL;
			}
			ListNode * curA = headA;
			ListNode * curB = headB;//先到结尾的相当于快指针
			unordered_set<ListNode *> dp;
			while (curA)
			{
				dp.insert(curA);
				curA = curA->next;
			}

			while (curB)
			{
				if (dp.count(curB))
				{
					return curB;
				}
				curB = curB->next;
			}
			return NULL;
		}

	ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
		if (NULL == headA || NULL == headB)
		{
			return NULL;
		}
		ListNode * curA = headA;
		ListNode * curB = headB;//先到结尾的相当于快指针
		while (1)
		{
			if (NULL == curA->next)
			{
				curA->next = headB;
			}

			if (NULL == curB->next)
			{
				curB->next = headA;
			}
			if (NULL == curB && NULL == curA)
			{
				return NULL;
			}

			if (curA == curB)
			{
				return curA;
			}
			curA = curA->next;
			curB = curB->next;
		}
    }
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
		if (NULL == headA || NULL == headB)
		{
			return NULL;
		}
		ListNode * curA = headA;//循环结束，就不能从头开始了，必须备份
		while (curA)
		{
			ListNode * curB = headB;
			while (curB)
			{
				if (curA == curB)
				{
					return curA;
				}
				curB = curB->next;
			}
			curA = curA->next;
		}
		return NULL;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int intersectVal = stringToInteger(line);
        getline(cin, line);
        ListNode* listA = stringToListNode(line);
        getline(cin, line);
        ListNode* listB = stringToListNode(line);
        getline(cin, line);
        int skipA = stringToInteger(line);
        getline(cin, line);
        int skipB = stringToInteger(line);
        
		ListNode* ret;// = Solution() .getIntersectionNode(intersectVal, listA, listB, skipA, skipB);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}




