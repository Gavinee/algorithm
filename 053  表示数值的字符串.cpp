/*
  题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123",
"3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

//author = Qiufeng

class Solution {
public:
    bool isNumeric(char* string)
    {
        int dot = 0;  //点
        int ch = 0;   //正负
        int Ee = 0;   //e或E
        int i = 0;    //遍历string的循环变量
        while(string[i]!='\0')
        {
            if(string[i]=='.' or string[i]=='+' or string[i] =='-' or string[i] =='e' or string[i]== 'E' or (string[i]>='0' and string[i]<='9'))
            {
                if(string[i]=='+' or string[i]=='-')
                {
                    ch++;
                    if(i!=0 and Ee == 0)
                        return false;
                }
                
                if(string[i] == 'e' or string[i] == 'E')
                {
                    Ee++;
                    if(Ee>1)
                        return false;
                    if(string[i+1]=='\0')
                        return false;
                    ch = 0;
                }
                
                if(string[i]=='.')
                {
                    dot++;
                    if(dot>1)
                        return false;
                    if(Ee>=1)
                        return false;
                }
            }
            else
            {
                return false;
            }
            i++;
        }
        
        if(ch>1)
            return false;
        
        return true;
    }
};
