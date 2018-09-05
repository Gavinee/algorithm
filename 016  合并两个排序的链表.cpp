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
        ListNode* temp;
        if(pHead1==nullptr) return pHead2;
        if(pHead2==nullptr) return pHead1;
        
        if(pHead1->val > pHead2->val)
        {
            temp = pHead2;
            temp->next = Merge(pHead1,pHead2->next);
        }
        else
        {
            temp = pHead1;
            temp->next = Merge(pHead1->next,pHead2);
        }
        return temp;
    }
};

/***************************非递归形式**********************************/
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

		if (pHead1 == nullptr and pHead2 == nullptr)
			return NULL;
		else if (pHead1 == nullptr)
			return pHead2;
		else if (pHead2 == nullptr)
			return pHead1;
		else
		{
			ListNode *tt, *temp;
			tt = new ListNode(0);
			tt->next = nullptr;
			temp = tt;
			while (pHead1 != nullptr and pHead2 != nullptr)
			{

				if (pHead1->val < pHead2->val)
				{
					temp->next = pHead1;
					pHead1 = pHead1->next;
				}
				else
				{
					temp->next = pHead2;
					pHead2 = pHead2->next;
				}
				temp = temp->next;
			}
			while (pHead2 != nullptr)
			{
				temp->next = pHead2;
				temp = temp->next;
				pHead2 = pHead2->next;
			}
			while (pHead1 != nullptr)
			{
				temp->next = pHead1;
				temp = temp->next;
				pHead1 = pHead1->next;
			}
			return tt->next;
		}
	}
};
