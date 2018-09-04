/*
  题目描述
  一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
//author = Qiufeng

/*
  思路：递推
  当number = 1时,way = 1
  当number = 2时，way = 2
  当number = 3时,way = 4   ,当最后一步为跨一步台阶，则way应为2,当最后一步为跨两步时，则way应为1,再可以一次跨n步，n = 3,则一共有2+1+1=4种跳法
  将所有小于number的way累加，再加上一步登天的一种方法，则共有pow(2,number-1)种跳法.
*/

#include<cmath>
class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2,number-1);
    }
};
