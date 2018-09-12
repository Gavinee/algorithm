/*
  题目描述
  请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层
  按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> tt;
        vector<vector<int>> target;
        int deep = 0;
        PrintTree(pRoot,tt,deep);
        
        for(int i = 0;i<tt.size();i++)
        {
            vector<int> temp;
            target.push_back(temp);
            for(int j = 0;j<tt[i].size();j++)
            {
                if(i%2==0)
                {
                    target[i].push_back(tt[i][j]);
                }
                else
                {
                    target[i].push_back(tt[i][tt[i].size()-1-j]);
                }
            }
            
        }
        
        return target;
    }
    
    void PrintTree(TreeNode *pRoot,vector<vector<int> > &Tree,int deep)
    {
        if(pRoot==NULL)
            return;
        if(deep+1> Tree.size())
        {
            vector<int> temp; 
            Tree.push_back(temp);
        }
        Tree[deep].push_back(pRoot->val);
        PrintTree(pRoot->left,Tree,deep+1);
        PrintTree(pRoot->right,Tree,deep+1);
    }
};
