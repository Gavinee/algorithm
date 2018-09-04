/*
  题目描述
  输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
//author = Qiufeng

/*
小技巧:
x&(x-1)可以将整数最右边的1变成0，通过这个小技巧，
我们只要循环判断n=n&(n-1)是否为0，即可统计1的个数。
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
             count++;
             n=n&(n-1);
         }
         return count;
     }
};
