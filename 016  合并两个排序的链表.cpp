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
        if(pHead1 == nullptr and pHead2 == nullptr)
            return NULL;
        else if(pHead1!=nullptr and pHead2 == nullptr)
            return pHead1;
        else if(pHead1 == nullptr and pHead2 != nullptr)
            return pHead2;
        else{
            ListNode* tt = new ListNode(0);
            tt->next = nullptr; 
            ListNode* temp;
            temp = tt;      //为链表头开辟一个头结点
            while(pHead1!=nullptr or pHead2!=nullptr)
                {
                    if(pHead1!=nullptr and pHead2!=nullptr and pHead1->val > pHead2->val)
                    {
                        temp->next = pHead2;
                        pHead2 = pHead2->next;
                        temp = temp->next;        //temp只是单个结点
                    }
                    else if(pHead1!=nullptr and pHead2!=nullptr and pHead1->val <= pHead2->val)
                    {
                        temp->next = pHead1;
                        pHead1 = pHead1->next;
                        temp = temp->next;
                    }
                    else if(pHead1==nullptr and  pHead2!=nullptr)
                    {
                        temp->next = pHead2;
                        pHead2 = pHead2->next;
                        temp = temp->next;
                    }
                    else if(pHead1!=nullptr and  pHead2 ==nullptr)
                    {
                        temp->next = pHead1;
                        pHead1 = pHead1->next;
                        temp = temp->next;
                    }
                    else
                    {
                        temp->next = nullptr;
                    }
                }
            return tt->next;        //temp只是链表的单个结点，而tt则是整个链表，
                                    //在输出合成后的链表，则需要删除第一个头结点
            }
	}
};

//注:nullptr在C++11中就是代表空指针，不能被转换成数字
//在编译器进行解释程序时，NULL会被直接解释成0
