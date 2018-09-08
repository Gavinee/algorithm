/*
  题目描述
  从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        vector<vector<int>> Print(TreeNode* pRoot) {
            int deep=1;
            vector<vector<int>> tt; 
            Tree(pRoot,deep,tt);
            return tt;
        }
    
        void Tree(TreeNode* pRoot,int deep,vector<vector<int>> &tt)
        {
            if(pRoot==NULL)
                return ;
            else
            {
                    if(deep>tt.size())
                    {
                        vector<int> temp;
                        for(int i =tt.size();i<deep;i++)
                            tt.push_back(temp);
                    }
                    tt[deep-1].push_back(pRoot->val);
                    Tree(pRoot->left,deep+1,tt);
                    Tree(pRoot->right,deep+1,tt);
           }
        }
};
