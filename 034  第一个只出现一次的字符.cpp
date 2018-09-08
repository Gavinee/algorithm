/*
  题目描述
  在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次
  的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

//author = Qiufeng

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<char> tt;
        vector<int> index;
        int cnt;
        if(str=="")
            return -1;
        
        for(int i = 0;i<str.length();i++)
        {
            if(i==0)
            {
                tt.push_back(str[0]);
                index.push_back(1);
                continue;
            }
            FindChar(tt,index,str[i]);
        }
        
        for(int j = 0;j < index.size();j++)
        {
            if(index[j] == 1)
            {
                cnt = j;
                break;
            }
            if(j == index.size()-1)
                return -1;
        }
        
        for(int k = 0;k<str.length();k++)
        {
            if(tt[cnt]==str[k])
            {
                cnt = k;
                break;
            }
        }
        return cnt;
    }
    
    void FindChar(vector<char> &tt,vector<int> &index,char temp)
    {
        for(int i = 0;i<tt.size();i++)
        {
            if(tt[i] == temp)
            {
                index[i] = index[i] + 1;
                return ;
            }
        }
        tt.push_back(temp);
        index.push_back(1);        
    }
};
