/*
  题目描述
  输入两个链表，找出它们的第一个公共结点。
*/

//author = Qiufeng

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        while(pHead2!=NULL)
        {
            if(FindFirst(pHead1,pHead2)!=NULL)
                return FindFirst(pHead1,pHead2);
            pHead2 = pHead2->next;
        }
        return NULL;
    }
    
    ListNode* FindFirst(ListNode* A, ListNode* B) 
    {
        if(A==NULL or B==NULL)
            return NULL;
        while(A!=NULL and B!=NULL)
        {
            if(A==B)
                return A;
            else
                A = A->next;
        }
        return NULL;
    }
};
