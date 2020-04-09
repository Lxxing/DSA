/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
//[12,null,-60],[12,null,72]
	bool isSameTree(TreeNode* p, TreeNode* q) {
			if (NULL == p && NULL == q)
			{
				return true;
			}
			
			std::queue<TreeNode* > travP;
			std::queue<TreeNode* > travQ;
			travP.push(p);
			travQ.push(q);
			while (travP.size() && travQ.size())
			{
				p = travP.front();
				q = travQ.front();
				travP.pop();
				travQ.pop();
				if (NULL == p && NULL == q)//可能是结束也可能是叶节点，直接return漏结果
				{
					continue;
				}
				if ( p && q && p->val == q->val )
				{
					travP.push(p->left);
					travP.push(p->right);
					travQ.push(q->left);
					travQ.push(q->right);
				}
				else
				{
					return false;
				}

			}
			return true;
			
		}


		
	//[1,2] [1,null,2]

    bool isSameTree1(TreeNode* p, TreeNode* q) {
		if (NULL == p && NULL == q)
		{
			return true;
		}

		if ( p && q && p->val == q->val )
		{
			return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
		}
		else
		{
			return false;
		}
		
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* q = stringToTreeNode(line);
        
        bool ret = Solution().isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

