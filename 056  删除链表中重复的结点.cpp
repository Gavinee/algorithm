/*
  题目描述
  在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
  返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//author = Qiufeng

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {        
        if(pHead==NULL)
            return pHead;

        ListNode* ppHead = new ListNode(0);
        ppHead->next = pHead;

        ListNode* pre = ppHead;
        while(pHead!=NULL)
        {
            ListNode* temp = pHead;
            while(temp->next!=NULL and temp->val == temp->next->val)
                temp = temp->next;
            
            if(temp==pHead)
            {
                pre = pHead;
                pHead = pHead->next;
            }

            if(temp!=pHead and temp !=NULL)
            {
                pre->next = temp->next;
                pHead = pre->next;
            }
        }
        return ppHead->next;
    }
};
