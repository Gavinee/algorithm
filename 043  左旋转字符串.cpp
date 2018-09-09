/*
  题目描述
  汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟
  这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例
  如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很
  简单？OK，搞定它！
*/

//author = Qiufeng

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string first;
        string temp;
        //if(n>str.length() or n<0)
        //    return NULL;
        for(int i = 0;i<str.length();i++)
        {
            if(i<n)
                first+=str[i];
            else
                temp+=str[i];
        }
        for(int i = 0;i<first.length();i++)
            temp+=first[i];
        return temp;
    }
};
