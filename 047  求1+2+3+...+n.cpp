/*
  题目描述
  求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
//author = Qiufeng

class Solution {
public:
    int Sum_Solution(int n) {
        int flag;
	int add = 1;
	flag = (n - 1) & -1;
	flag && (add = n + Sum_Solution(n - 1));
	return add;
    }
};
