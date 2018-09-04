/*
  题目描述
  请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
  则经过替换之后的字符串为We%20Are%20Happy。
*/
// author = Qiufeng

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int i = 0;
        for(i = 0;i<length;i++)
        {
            if(str[i] == ' ')
            {
                str[length] = str[length-2];
                str[length+1] = str[length-1];
                int j = length;
                for(j;j>i+2;j--)
                {
                    str[j-1] = str[j-3];
                }
                str[i] = '%';
                str[i+1] = '2';
                str[i+2] = '0';
                length+=2;
                i = i+2;
                
            }
        }
	}
};
