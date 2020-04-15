/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	bool hasPathSum1(TreeNode* root, int sum) {
			if (!root)
			{
				return false;
			}
			if (!root->left && !root->right && root->val == sum)
			{
				return true;
			}
			else if(!root->left && !root->right && root->val != sum)
			{
				return false;
			}
			
			return hasPathSum(root->left,sum - root->val) ||
						hasPathSum(root->right,sum - root->val);

	}

    bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
		{
			return false;
		}

		stack<pair<TreeNode*, int> > stackQ;
		stackQ.push(pair<TreeNode*, int>(root, sum));
		TreeNode *node = root;
		int levelSum = sum;

		while (stackQ.size())
		{
			node = stackQ.top().first;
			levelSum = stackQ.top().second;
			stackQ.pop();

			if (!node->left && !node->right && node->val == levelSum)
			{
				return true;
			}
			if(node->left)
			{
				stackQ.push(pair<TreeNode*, int>(node->left,levelSum - node->val));
			}
			if(node->right)
			{
				stackQ.push(pair<TreeNode*, int>(node->right,levelSum - node->val));
			}
		}
		return false;

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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        bool ret = Solution().hasPathSum(root, sum);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

