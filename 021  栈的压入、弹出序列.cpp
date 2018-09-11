/*
  题目描述
  输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
  假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
  栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序
  列的长度是相等的）
*/

//author = Qiufeng

class Solution {
public:

    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> Stack;

        int pushIndex = 0;
        int popIndex = 0;
        while (popIndex<popV.size())
        {
            if (FindIndex(pushV, pushIndex, popV[popIndex]))
            {
                if (Stack.empty())
                {
                    Stack.push(pushV[pushIndex]);
                    pushIndex++;
                }
                while (!Stack.empty() && popV[popIndex] != Stack.top())   //向栈中增加元素
                {
                    Stack.push(pushV[pushIndex]);
                    pushIndex++;
                }
                Stack.pop();
            }
            else
            {
                while (!Stack.empty() && popV[popIndex] != Stack.top())
                    Stack.pop();
                if (Stack.empty())
				    return false;
            }
            popIndex++;
        }
        return true;
    }

    bool FindIndex(vector<int> pushV, int pushIndex, int Value)
    {
        if (pushIndex >= pushV.size())
            return false;
        for (int i = pushIndex; i<pushV.size(); i++)
        {
            if (pushV[i] == Value)
            {
                return true;
            }
        }
        return false;
    }
};
