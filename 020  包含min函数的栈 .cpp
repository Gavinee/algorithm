/*
  题目描述
  定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//author = Qiufeng

class Solution {
public:
    vector<int> tt;
    void push(int value) {
        tt.push_back(value);
    }
    void pop() {
        if(tt.size()!=0)
        {
            vector<int> temp;
            for(int i = 0;i<tt.size()-1;i++)
                temp.push_back(tt[i]);
            tt = temp;
        }
        
    }
    int top() {
        if(tt.size()!=0)
            return tt[tt.size()-1];
        else
            return NULL;
    }
    int min() {
        int temp;
        if(tt.size()==0)
            return NULL;
        if(tt.size()==1)
            return tt[0];
        if(tt.size()>1)
        {
            temp = tt[0];
            for(int i =1 ;i<tt.size();i++)
                if(temp>tt[i])
                    temp = tt[i];
        }
        return temp;
    }
};
