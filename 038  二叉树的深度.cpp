/*
  题目描述
  输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        if(pRoot->left == NULL and pRoot->right == NULL)
            return 1;
        
        vector<int> deep;
        int temp;
        int nowDeep =1;
        MostTreeDepth(pRoot,deep,nowDeep);
        
        temp = deep[0];
        for(int i = 1;i < deep.size();i++)
        {
            if(temp < deep[i])
                temp = deep[i];
        }
        return temp;
    }
    
    void MostTreeDepth(TreeNode* pRoot,vector<int> &deep,int nowDeep)
    {
        if(pRoot->left==NULL and pRoot->right==NULL)
            deep.push_back(nowDeep);
        else if(pRoot->left!=NULL and pRoot->right == NULL)
            MostTreeDepth(pRoot->left,deep,nowDeep+1);
        else if(pRoot->left==NULL and pRoot->right !=NULL)
            MostTreeDepth(pRoot->right,deep,nowDeep+1);
        else
        {
            MostTreeDepth(pRoot->left,deep,nowDeep+1);
            MostTreeDepth(pRoot->right,deep,nowDeep+1);
        }
    }  
};

/*****************************************优化后**********************************************/
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        
        vector<int> deep;
        int nowDeep =0;
        MostTreeDepth(pRoot,deep,nowDeep);
        
        return deep[0];
    }
    
    void MostTreeDepth(TreeNode* pRoot,vector<int> &deep,int nowDeep)
    {
        if(pRoot == NULL)   
            if(deep.size()==0)
                return deep.push_back(nowDeep);
            else
            {
                if(nowDeep>deep[0])
                    deep[0] = nowDeep;
                return;
            }

         MostTreeDepth(pRoot->left,deep,nowDeep+1);
         MostTreeDepth(pRoot->right,deep,nowDeep+1);
    }
};
