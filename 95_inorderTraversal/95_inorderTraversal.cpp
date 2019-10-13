// 95_inorderTraversal.cpp : 定义控制台应用程序的入口点。
//

/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
1
\
2
/
3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;

/**
* Definition for a binary tree node.
**/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void inorderTraversal(TreeNode* root, vector<int>&res) {
		if (!root)return;
		inorderTraversal(root->left, res);
		res.push_back(root->val);
		inorderTraversal(root->right, res);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)return{};
		vector<int> res;
		TreeNode* tmp = root;
		stack<TreeNode*> q;
		while (tmp || q.size()>0)
		{
			if (tmp) {
				q.push(tmp);
				tmp = tmp->left;
				continue;
			}
			tmp = q.top();
			q.pop();
			res.push_back(tmp->val);
			tmp = tmp->right;
		}
		return res;
	}
};

int main()
{
    return 0;
}

