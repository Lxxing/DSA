/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	bool isSymmetricR(TreeNode* left,TreeNode* right)
	{
		if (NULL == left && NULL == right)
		{
			return true;
		}
		if (left && right && left->val == right->val)
		{
			return isSymmetricR(left->left,right->right) 
				&& isSymmetricR(left->right,right->left);
		}
		return false;
	}
    bool isSymmetric(TreeNode* root) {
		if (NULL == root)
		{
			return true;
		}
		return isSymmetricR(root->left,root->right);
    }

    bool isSymmetric1(TreeNode* root) {
		if (NULL == root)
		{
			return true;
		}
		queue<TreeNode *> travLevel;
		travLevel.push(root);
		travLevel.push(root);
		while (travLevel.size())
		{
			TreeNode * p = travLevel.front();
			travLevel.pop();
			TreeNode *q = travLevel.front();
			travLevel.pop();
			if (NULL == p && NULL == q)
			{
				continue;
			}
			if ( p && q && p->val == q->val )
			{
				travLevel.push(p->left);
				travLevel.push(q->right);
				travLevel.push(p->right);
				travLevel.push(q->left);
			}
			else
			{
				return false;
			}

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
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isSymmetric(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}


