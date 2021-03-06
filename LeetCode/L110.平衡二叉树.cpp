/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	int Hight(TreeNode* node)
	{
		if (!node)
		{
			return 0;
		}

		int left = Hight(node->left);
		int right = Hight(node->right);
		return max(left,right) + 1;
	}
    bool isBalanced(TreeNode* root) {
		if (!root)
		{
			return true;//空树平衡
		}
		//除了判断当前节点还递归子树是否平衡
        return abs(Hight(root->left) - Hight(root->right)) <= 1 &&
        		isBalanced(root->left) && 
        		isBalanced(root->right); 
    }
    int isBalancedR(TreeNode* node,int & height)
	{
		if (!node)
		{
			height = -1;
			return true;
		}

		int left;
		bool isL = isBalancedR(node->left,left);
		int right;
		bool isR = isBalancedR(node->right,right);
		if (isL && isR && abs(left - right) < 2)
		{
			height = max(left,right) + 1;
			return true;
		}
		return false;
	}
    bool isBalanced1(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		int height = 0;
        return isBalancedR(root,height); 
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
        
        bool ret = Solution().isBalanced(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

