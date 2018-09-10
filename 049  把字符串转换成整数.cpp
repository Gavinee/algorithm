/*
  题目描述
  将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
  输入描述:
  输入一个字符串,包括数字字母符号,可以为空
  输出描述:
  如果是合法的数值表达则返回该数字，否则返回0
  
  示例1
  输入
  +2147483647
  1a33
  
  输出
  2147483647
  0
*/

//author = Qiufeng

#include<string>
#include<sstream>

class Solution {
public:
    int StrToInt(string str) {
        int count = 0;
        for(int i = 0;i < str.length();i++)
        {
            for(int j = '0';j <='9';j++)
            {
                if(str[i]==j)
                {
                    count++;
                }
            }
        }
        
        stringstream ss;
        int tt;
        ss<<str;
        ss>>tt;
        
        int temp;
        temp = tt;
        while(temp%10!=0 or temp/10!=0)
        {
            temp/=10;
            count--;
        }
        
        if(count>0)        //加括号和不加括号的结果不一样。加括号能运行成功。
            return 0;
        else
            return tt;
    }
};
