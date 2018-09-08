/*
  题目描述
  输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

//author = Qiufeng

//此代码参考了周旭龙的代码，网址为http://www.cnblogs.com/edisonchou/p/4771939.html

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
        bool result = false;
        
        if(pRoot1!=NULL and pRoot2!=NULL)
        {
            if(pRoot1->val ==pRoot2->val)
               result = SubTree(pRoot1,pRoot2); 
            if(!result)
                result = SubTree(pRoot1->left,pRoot2);
            if(!result)
                result = SubTree(pRoot1->right,pRoot2);
        }
     return result;
    }
    
    bool SubTree(TreeNode* A,TreeNode* B)
    {
        if(B == NULL)                    //这一个if语句和下面一个if语句位置不能放反了。
            return true;
        if(A == NULL)
            return false;
        if(A->val !=B->val) return false;
        return SubTree(A->left,B->left)&&SubTree(A->right,B->right);
    }
};
