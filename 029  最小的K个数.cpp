/*
  题目描述
  输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
//author = Qiufeng

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> temp;
        
        if(k>input.size())
        {
            return temp;
        }
        
        BubbleSort(input);
        
        for(int i = 0;i<k;i++)
        {
            temp.push_back(input[i]);
        }
        return temp;
    }
    
    void BubbleSort(vector<int> &tt)
    {
        int cnt;
        for(int i = 0;i < tt.size();i++)
        {
            for(int j = 0;j < tt.size()-i-1;j++)
            {
                if(tt[j]>tt[j+1])
                {
                    cnt = tt[j];
                    tt[j] = tt[j+1];
                    tt[j+1] = cnt;
                }
            }
        }
    }
};
