/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:
	void DFS(TreeNode* node,int depth,vector<vector<int>>&result)
	{
		if (NULL == node)
		{
			return;
		}
		if (result.size() == depth)
		{
			result.emplace_back();
		}
		result[depth].push_back(node->val);
		if (node->left)
		{
			DFS(node->left,depth + 1,result);
		}
		if (node->right)
		{
			DFS(node->right,depth + 1,result);
		}
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
		DFS(root,0,result);
        
		return vector<vector<int>>(result.rbegin(),result.rend());;
    }
    vector<vector<int>> levelOrderBottom1(TreeNode* root) {
        vector<vector<int>> result;

        queue<pair<TreeNode*,int> > travlQ;
        travlQ.push(pair<TreeNode*, int>(root,1));

		while (travlQ.size())
		{
			TreeNode* node = travlQ.front().first;
			int levelNum = travlQ.front().second;
			travlQ.pop();
			if (!node)
			{
				continue;//叶节点
			}
			if (result.size() < levelNum)
			{
				result.resize(levelNum);
			}
			
			result[levelNum - 1].push_back(node->val);
			++levelNum;
			travlQ.push(pair<TreeNode*, int>(node->left,levelNum));
			travlQ.push(pair<TreeNode*, int>(node->right,levelNum));
		}
		reverse(result.begin(),result.end());
		return result;
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<vector<int> > ret = Solution().levelOrderBottom(root);
    }
    return 0;
}


