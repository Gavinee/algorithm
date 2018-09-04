/*
  题目描述
  大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
  n<=39
*/
//author = Qiufeng

class Solution {
public:
    int Fibonacci(int n) {
        vector<int> sum;
        int temp;
        int i;
        for (i = 0; i <= n; i++)
	    {
            if (i == 0)
                sum.push_back(0);
            else if (i == 1)
                sum.push_back(1);
            else 
            {
                temp = sum[sum.size() - 1] + sum[sum.size() - 2];
                sum.push_back(temp);
            }
	     }
        return sum[sum.size()-1];
    }
};
