/*
  题目描述
  给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

//author = Qiufeng

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size());
        for(int i = 0;i<A.size();i++)
        {
            B[i] = 1;
            for(int j = 0;j<A.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                B[i]*=A[j];
            }
        }
        return B;
    }
};
