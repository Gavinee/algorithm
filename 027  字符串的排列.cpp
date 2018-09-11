/*
  题目描述
  输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字
  符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
  
  输入描述:
  输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

//author = Qiufeng

class Solution {
public:
    vector<string> Permutation(string str)
    {
        vector<string> tt;
        string cnt;

        if(str.length()==0)
            return tt;
        backData(tt,str,cnt);
        return tt;
    }

    //tt  :    返回的vector容器
    //str ：   下一次字符串
    //cnt :    返回到vector中的string
    void backData(vector<string> &tt, string str,string cnt)
    {
        string temp;
        string pp = "";
        temp = cnt;
        if (str.length() == 0)
        {
            for(int k = 0;k < tt.size();k++)
                if(tt[k]==cnt)
                    return;
            tt.push_back(cnt);
            return;
        }
        
        for (int j = 0; j < str.length(); j++)
        {
            temp += str[j];
            for(int i = 0;i<str.length();i++)
                if(i!=j)
                    pp+=str[i];
            backData(tt,pp,temp);
            temp = cnt;
            pp = "";
        }
    }
};
