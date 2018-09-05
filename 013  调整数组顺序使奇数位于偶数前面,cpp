/*
  题目描述
  输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半
  部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

// author = Qiufeng
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arrayOdd;
        vector<int>  arrayEven;
        int count = 0;
        for(int i = 0;i < array.size();i++)
        {
            if(array[i]%2==1)
                arrayOdd.push_back(array[i]);
            if(array[i]%2==0)
                arrayEven.push_back(array[i]);
        }
        while(arrayOdd.size()!=0)
        {
            array[count] = arrayOdd[0];
            arrayOdd.erase(arrayOdd.begin(),arrayOdd.begin()+1);
            count++;
        }
        while(arrayEven.size()!=0)
        {
            array[count] = arrayEven[0];
            arrayEven.erase(arrayEven.begin(),arrayEven.begin()+1);
            count++;
        }
    }
};

