/*
  题目描述
  操作给定的二叉树，将其变换为源二叉树的镜像。
  输入描述:
  二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/

//本题参考了博客园昵称为csbdong博主的编程思路，链接附上：https://www.cnblogs.com/csbdong/p/5701070.html

//  author = Qiufeng

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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return ;
        
        TreeNode *temp ;
        if(pRoot->left!=NULL or pRoot->right!=NULL)
        {
            temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        else
            return ;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
