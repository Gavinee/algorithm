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
        for(int i = 0;i <= str.length();i++)
        {
            if(str[i]==chr or str[i] =='\0')
            {
                reSentence.push(tt);
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
