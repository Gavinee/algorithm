/*
  题目描述
  输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
// author = qiufeng

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> array;
        stack<int> stack1;
        while(head)
        {
            stack1.push(head->val);
            head = head->next;
        }
        while(!stack1.empty())
        {
            array.push_back(stack1.top());
            stack1.pop();
        }
        return array;
        
    }
};
