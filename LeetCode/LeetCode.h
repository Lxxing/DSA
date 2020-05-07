/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#ifndef __LEET_CODE__H_
#define __LEET_CODE__H_


#include <iostream> 
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode {
	  int val;
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode() : val(0), left(nullptr), right(nullptr) {}
	  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
	  int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
};

#endif //__LEET_CODE__H_

