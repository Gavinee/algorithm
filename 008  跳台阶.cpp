/*
  题目描述
  一只青蛙一次可以跳上1级台阶，也可以跳上2级。
  求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
// author = Qiufeng

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> way;
        int temp;
        for(int i = 1;i<=number;i++)
        {
            if(i==1)
                way.push_back(1);
            else if(i==2)
                way.push_back(2);
            else
            {
                temp = way[way.size()-1] + way[way.size()-2];
                way.push_back(temp);
            }
        }
        return way[way.size()-1];
    }
};
