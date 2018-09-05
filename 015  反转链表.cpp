/*
  题目描述
  输入一个链表，反转链表后，输出新链表的表头。
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
class Solution {            //将链表所指的方向依次倒置。
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;
        while(pNode!=NULL)
        {
            ListNode* pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pPrev;
    }
};
