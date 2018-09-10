/*
  题目描述
  输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

//author = Qiufeng

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        return (abs(getDepth(pRoot->left)-getDepth(pRoot->right))<=1)&&(IsBalanced_Solution(pRoot->left))&&(IsBalanced_Solution(pRoot->right));
    }
    
    int getDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        
        int len1 = getDepth(pRoot->left);
        int len2 = getDepth(pRoot->right);
        
        return ((len1 > len2)?len1:len2)+1;
    }
};
