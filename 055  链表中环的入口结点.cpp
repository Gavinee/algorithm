/*
  题目描述
  给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出NULL。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        vector<ListNode*> tt;
        
        while(pHead!=NULL)
        {
            if(tt.size()==0)
            {
                tt.push_back(pHead);
            }
            else
            {
                for(int i = 0;i<tt.size();i++)
                {
                    if(pHead == tt[i])
                    {
                        return tt[i];
                    }
                }
                tt.push_back(pHead);
            }
            pHead = pHead->next;
        }
        return NULL;
    }
};
