/*
  题目描述
  一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/

//author = Qiufeng

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
        vector<int>tt;
        vector<int>count;
        vector<int>record;
        
        tt.push_back(data[0]);
        count.push_back(1);
        
        FindNums(data,tt,count);

        for(int i = 0;i<count.size();i++)
        {
            if(count[i] == 1)
                record.push_back(tt[i]);
        }
        
        *num1 = record[0];          //*num1 = record[0] 学习了。
        *num2 = record[1];
    }
    
    void FindNums(vector<int> data,vector<int> &tt,vector<int> &count)
    {
        for(int i =1;i<data.size();i++)
        {
            for(int j = 0;j<tt.size();j++)
            {
                if(tt[j]==data[i])
                {
                    count[j]++;
                    break;
                }
                if(j==tt.size()-1 and tt[j]!=data[i])
                {
                    tt.push_back(data[i]);
                    count.push_back(1);
                    break;
                }
            }
        }
    }
};
