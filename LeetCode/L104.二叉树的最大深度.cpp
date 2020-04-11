/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"

class Solution {
public:

	int maxDepth(TreeNode* root) {
			if (NULL == root)
			{
				return 0;
			}
	
			stack<pair<TreeNode* ,int > > travlQ;

			int result = -1;
			int levelNum = 0;
			do
			{
				while ( root )
   				{
      				travlQ.push(pair<TreeNode* ,int >(root,++levelNum)); 
      				root = root->left;  
  				}
				root = travlQ.top().first;
				levelNum = travlQ.top().second;
				travlQ.pop();
				result = max(result,levelNum);
				root = root->right;
			}while (travlQ.size() || root != NULL);//可能返回根

			return result;
		}

	int maxDepth1(TreeNode* root) {
			if (NULL == root)
			{
				return 0;
			}

			queue<pair<TreeNode* ,int > > travlQ;
			travlQ.push({root,1});
			int result = -1;
			while (travlQ.size())
			{
				
				TreeNode* node = travlQ.front().first;
				int levelNum = travlQ.front().second;
				travlQ.pop();
				if (node)
				{
				    result = max(result,levelNum);//防止叶节点
					travlQ.push({node->left,levelNum+1});
					travlQ.push({node->right,levelNum+1});
				}

			}
			return result;
		}
	int maxDepth2(TreeNode* root) {
			if (NULL == root)
			{
				return 0;
			}

			queue<TreeNode* > travlQ;
			travlQ.push(root);
			int result = -1;
			while (travlQ.size())
			{
				result++;

				int levelNum = travlQ.size();
				for (int i = 0; i < levelNum; ++i)
				{
					TreeNode* node = travlQ.front();
					travlQ.pop();
					if (node)
					{
						travlQ.push(node->left);
						travlQ.push(node->right);
					}
				}
				

			}
			return result;
		}



    int maxDepth3(TreeNode* root) {
		if (NULL == root)
		{
			return 0;
		}
		int leftMax = maxDepth(root->left) + 1;
		int rightMax = maxDepth(root->right) + 1;
		return max(leftMax,rightMax);
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
        
        int ret = Solution().maxDepth(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

