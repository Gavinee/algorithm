/*
  题目描述
  输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历
  和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}
  和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
// author = qiufeng

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int i= 0, j = 0;
		int vin_index = 0;
		vector<int> pre_left, pre_right, vin_left, vin_right;

		if (pre.size() == 0)
			return  NULL;   //如果在此处返回一个空的tree,则会显示程序超时。
		TreeNode* tree = new TreeNode(pre[0]);
        
		for (i = 0; i<vin.size(); i++)
			if (pre[0] == vin[i])
			{
				vin_index = i;
				break;
			}

		for (j = 0; j<vin.size(); j++)
        {
			if (j >= 1 && j<vin_index + 1)
				pre_left.push_back(pre[j]);
		    if (j<vin_index)
			    vin_left.push_back(vin[j]);
		    if (j >= vin_index + 1)
			    pre_right.push_back(pre[j]);
		    if (j >= vin_index + 1)
			    vin_right.push_back(vin[j]);
        }
        
		tree->left = reConstructBinaryTree(pre_left, vin_left);
		tree->right = reConstructBinaryTree(pre_right, vin_right);
		return tree;
	}
};
