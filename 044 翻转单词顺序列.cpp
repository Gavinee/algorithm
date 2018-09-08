/*
  题目描述
  牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
  同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例
  如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的
  句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他
  么？
*/
//author = Qiufeng

class Solution {
public:
    string ReverseSentence(string str) {
        char chr = ' ';
        string tt="";
        stack<string> reSentence;
        for(int i = 0;i <= str.length();i++)      //字符串的区间是[0,str.length()],两边闭区间，而数组则是[0,tt.size())
        {
            if(str[i]==chr or str[i] =='\0')      //若将区间改为[0,str.length()),忽略str[length] == '\0',而采用直接截取                               
            {                                     //到length()-1的字符，则输出会报错(报错原因是输出与要求的不一样。。。。)
                reSentence.push(tt);              //所以，采用str[i] == '\0'作为判断条件，保留了字符串的完整性。
                tt = "";
            }
            else
                tt+=str[i];
        }
         
        tt = "";
        string qq = "";
        int i = 0;
        while(i<reSentence.size())
        {
            tt+= reSentence.top();
            qq+=tt;
            reSentence.pop();
            tt = " ";
        }
        return qq;
    }
};
