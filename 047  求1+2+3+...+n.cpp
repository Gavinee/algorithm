
/*

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
