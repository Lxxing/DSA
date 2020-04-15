/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"


class Solution {
public:
	bool DFS(TreeNode* root, TreeNode* desNode,stack<TreeNode*> &travelQ)
	{
		if (!root)
		{
			return false;
		}
		travelQ.push(root);
		if (root->val == desNode->val)
		{
			return true;
		}

		bool isFind = false;
		if (!isFind && root->left)
		{
		    isFind = DFS(root->left,desNode,travelQ);
		}
		if (!isFind && root->right)
		{
			isFind = DFS(root->right,desNode,travelQ);
		}

		if (!isFind)
		{
			travelQ.pop();
		}
		return isFind;

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			stack<TreeNode*> travelP;
			DFS(root,p,travelP);
			stack<TreeNode*> travelQ;
			DFS(root,q,travelQ);
			int sizeP = travelP.size();
			int sizeQ = travelQ.size();
			int delta = abs(sizeP - sizeQ);
			if (sizeP < sizeQ)
			{
				while (delta--)
				{
					travelQ.pop();
				}
			}
			else
			{
				while (delta--)
				{
					travelP.pop();
				}
			}
			while (travelP.size())
			{
				TreeNode*nodep = travelP.top();
				travelP.pop();
				TreeNode*nodeq = travelQ.top();
				travelQ.pop();
				if (nodep->val == nodeq->val)
				{
					return nodep;
				}
			}
			return NULL;
		}
		

    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
		{
			return NULL;
		}

		if ((p->val == root->val || q->val == root->val))
		{
			return root;
		}

		TreeNode*left = lowestCommonAncestor(root->left,p,q);
		TreeNode*right = lowestCommonAncestor(root->right,p,q);
		if (!left)
		{
			return right;
		}
		if (!right)
		{
			return left;
		}
		return root;
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

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int p = stringToInteger(line);
        getline(cin, line);
        int q = stringToInteger(line);
        
       TreeNode* ret = Solution().lowestCommonAncestor(root, &TreeNode(p), &TreeNode(q));

        string out = to_string(ret->val);
        cout << out << endl;
    }
    return 0;
}

