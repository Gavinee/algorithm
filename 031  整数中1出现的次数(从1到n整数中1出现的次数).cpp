/*
  题目描述
  求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13
  中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你
  们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出
  现的次数）。
*/

//author = Qiufeng

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i = 1;i<=n;i++)
        {
            int copy = i;
            int temp;
            while(copy/10!= 0 or copy%10!=0)
            {
                temp = copy%10;
                if(temp==1)
                    count++;
                copy/=10;
            }
        }
        return count;
    }
};
