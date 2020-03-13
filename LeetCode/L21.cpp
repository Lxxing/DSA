/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
21. 合并两个有序链表
******************************************************************************************/
#include "LeetCode.h"


/**
 * Definition for singly-linked list. 
 */
 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (NULL == l1)
		{
			return l2;
		}
		if (NULL == l2)
		{
			return l1;
		}

		if ( l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);//l1值确定
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);//l2值确定
			return l2;
		}
	
    }
};
 class Solution3{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode pHead(INT_MIN);
		ListNode * pPre = &pHead;
		while (l1 != NULL && l2 != NULL)
		{
			if ( l1->val < l2->val)
			{
				pPre->next = l1;
				l1 = l1->next;
			}
			else
			{
				pPre->next = l2;
				l2 = l2->next;				
			}
			pPre = pPre->next;//pPre前进
		}
		//必有一个空节点，pPre链接非空即可
		pPre->next = l1 ?  l1 : l2;
		return pHead.next;
    }
};
//建立链表，不要拷贝，利用原本链表
 class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * pHead = new ListNode(INT_MIN);//初始化不指向任何
		ListNode * pPre = pHead;
		while (l1 != NULL && l2 != NULL)
		{
			if ( l1->val <= l2->val)
			{
				pPre->next = l1;
				l1 = l1->next;
			}
			else
			{
				pPre->next = l2;
				l2 = l2->next;				
			}
			pPre = pPre->next;//pPre前进
		}
		//必有一个空节点，pPre链接非空即可
		NULL == l1 ? pPre->next = l2 : pPre->next = l1;
		pPre = pHead->next;
		delete pHead;//动态分配可以去掉
		return pPre;
    }
};
class Solution1{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (NULL == l1 && NULL != l2) return l2;
		if (NULL == l2 && NULL != l1) return l1;
		
		ListNode * pHead1 = l1;
		ListNode * pPre1 = l1;
		ListNode * pHead2 = l2;
		while (pHead1 != NULL || pHead2 != NULL)
		{
			if ((pHead1 != NULL) && (pHead2 == NULL || pHead1->val <= pHead2->val))
			{
				pPre1 = pHead1;
				pHead1 = pHead1->next;
			}
			if ((pHead2 != NULL) && (pHead1 == NULL || pHead1->val > pHead2->val))
			{
				pPre1->next = pHead2;//链接
				pPre1 = pPre1->next;
				pHead2 = pHead2->next;//l2前进,保护l2
				pPre1->next = pHead1;//恢复
				
			}
		}
		return l1;
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
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

