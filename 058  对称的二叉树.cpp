/*
  题目描述
  请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        vector<int> tt;
        vector<int> qq;
        if(pRoot==NULL)
            return true;
        dfs(pRoot,tt);
        mirrorTree(pRoot);
        dfs(pRoot,qq);
        
        for(int i =0 ;i<tt.size();i++)
        {
            if(tt[i]!=qq[i])
                return false;
        }
        return true;
    }
    
    void mirrorTree(TreeNode* &pRoot)      //树的镜像
    {
        TreeNode* Tree;
        if(pRoot->left!=NULL or pRoot->right!=NULL)
        {
            Tree = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = Tree;
            if(pRoot->left!=NULL)
                mirrorTree(pRoot->left);
            if(pRoot->right!=NULL)
                mirrorTree(pRoot->right);
        }
        else
            return;
    }
    
    void dfs(TreeNode* A,vector<int> &tt)        //谦虚遍历
    {
        if(A!=NULL)
        {
            tt.push_back(A->val);
            dfs(A->left,tt);
            dfs(A->right,tt);
        }
        tt.push_back(0);
    }
};
