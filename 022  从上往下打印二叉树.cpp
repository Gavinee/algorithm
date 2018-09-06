/*
  题目描述
  从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
// author = Qiufeng

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        vector<int> tt;
        
        if(root==NULL)
            return tt;
        tt.push_back(root->val);
        TreeTransfromVector(root,tt);
        return tt;
    }
    
    void TreeTransfromVector(TreeNode* temp,vector<int> &tt)
    {
        if(temp->left!=NULL and temp->right!= NULL)
        {
            tt.push_back(temp->left->val);
            tt.push_back(temp->right->val);
            TreeTransfromVector(temp->left,tt);
            TreeTransfromVector(temp->right,tt);
        }
        
        if(temp->left!=NULL and temp->right== NULL)
        {
            tt.push_back(temp->left->val);
            TreeTransfromVector(temp->left,tt);
        }
        
        if(temp->right!=NULL and temp->left== NULL)
        {
            tt.push_back(temp->right->val);
            TreeTransfromVector(temp->right,tt);
        }
    }
};
