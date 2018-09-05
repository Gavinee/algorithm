/*
  题目描述
  给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

// author = Qiufeng

/*********************Method One**************************/

#include<cmath>
class Solution {
public:
    double Power(double base, int exponent) {
        return pow(base,exponent);
    }
};


/*********************Method Two**************************/
class Solution {
public:
    double Power(double base, int exponent) {
        long double temp =1;
        if(exponent >=0)
            for(int i = 0;i < exponent;i++)
                temp*=base;
        else
            for(int i = 0;i > exponent;i--)
                temp/=base;
        return temp;
    }
};
