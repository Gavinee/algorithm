/*
  题目描述
  统计一个数字在排序数组中出现的次数。
*/

//author = Qiufeng

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        vector<int>tt;
        vector<int>count;
        int temp ;
        if(data.size()==0)
            return NULL;
        
        tt.push_back(data[0]);
        count.push_back(1);
        
        FindNums(data,tt,count);

        for(int i = 0;i<tt.size();i++)
        {
            if(tt[i] == k)
            {
                temp = i;
                break;
            }
            if(i == count.size()-1 and tt[i] !=k)
            {
                return NULL;
            }
        }
        return count[temp];
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
