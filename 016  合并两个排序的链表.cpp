/*
  1题目描述

  输入两个单调递增的链表，输出两个链表合成后的链表当然我们需要合成后的链表满足单调不减规则。
*/

// author = Qiufeng

/************************递归形式*************************************/
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;
        
        ListNode* pMergeHead = nullptr;
        
        if(pHead1->val < pHead2 -> val)
        {
            pMergeHead = pHead1;
            pMergeHead->next = Merge(pHead1->next,pHead2);
        }
        else{
            pMergeHead = pHead2;
            pMergeHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergeHead;
    }
};

/***************************非递归形式**********************************/

