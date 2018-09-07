/*
  题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不
存在则输出0。
*/
//author = Qiufeng

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        vector<int> tt;
        vector<int> times;
        
        for(int i = 0;i<numbers.size();i++)
        {
            if(tt.size()== 0)
            {
                tt.push_back(numbers[0]);
                times.push_back(1);
                continue;
            }
            for(int j = 0;j<tt.size();j++)
            {
                if(numbers[i]==tt[j])
                {
                    times[j] = times[j] + 1;
                    break;
                }
                if(j == tt.size()-1 and numbers[i]!=tt[j])
                {
                    tt.push_back(numbers[i]);
                    times.push_back(1);
                    break;
                }
            }
        }
        for(int i =0 ;i<times.size();i++)
        {
            if(times[i]>numbers.size()/2)
                return tt[i];
        }
        return 0;
    }
};
