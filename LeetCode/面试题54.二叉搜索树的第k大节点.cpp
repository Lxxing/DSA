/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"

class Solution {
public:
	void DFS(TreeNode* node,vector<int> &nums)
	{
		if (!node)
		{
			return;
		}
		if (!node->left && !node->right)
		{
			nums.push_back(node->val);
			return;
		}
		DFS(node->left,nums);
		nums.push_back(node->val);
		DFS(node->right,nums);
	}
    int kthLargest(TreeNode* root, int k) {
		if (!root)
		{
			return INT_MIN;
		}
		vector<int> result;
		DFS(root,result);

		return result[result.size() -  k];
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().kthLargest(root, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

