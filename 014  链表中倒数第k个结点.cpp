/*
  题目描述
  输入一个链表，输出该链表中倒数第k个结点。
*/

// author = Qiufeng

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* node;
        ListNode* temp = pListHead;
        unsigned int count = 1;
        
        if(temp==NULL)
            return NULL;           //不能返回node,否则结点中自动生成random元素。造成结果错误。
        while(temp->next!=NULL)
        {
            temp = temp->next;
            count++;
        }
        
        if(k>count)
            return NULL;
        else
        {
            count = count - k;
            while(count>0)
            {
                pListHead = pListHead->next;
                count--;
            }
            node = pListHead;
            return node;
        }
    }
};
