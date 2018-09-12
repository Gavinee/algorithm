/*
  题目描述
  输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路
  径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注
  意: 在返回值的list中，数组长度大的数组靠前)
*/

//author = Qiufeng

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {   //必须从根到叶子节点
        vector<vector<int> > tt;
        vector<int> temp;
        
        EqualValuePath(root,expectNumber,temp,tt);
        return tt;
    }
    
    void EqualValuePath(TreeNode* root,int expectNumber,vector<int> temp,vector<vector<int>> &tt)
    {
        if(root==NULL)
            return;
        
        temp.push_back(root->val);
        expectNumber -= root->val;
        if(root->left==NULL and root->right == NULL and expectNumber == 0)
            tt.push_back(temp);
        
         EqualValuePath(root->left,expectNumber,temp,tt);
         EqualValuePath(root->right,expectNumber,temp,tt);
    }
};
