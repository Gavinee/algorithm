/*
  题目描述
  输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们
  的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
  
  输出描述:
  对应每个测试案例，输出两个数，小的先输出
*/

//author = Qiufeng

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> mintt;
        vector<int> numbers;
        vector<int> result;
        
        if(array.size()==0)
            return result;
        
        for(int i =0;i<array.size();i++)
        {
            int other;
            other = sum - array[i];
            
            if(other>array[array.size()-1])
                continue;
            if(other==array[array.size()-1])
            {
                mintt.push_back(array[i]*other);
                numbers.push_back(array[i]);
                continue;
            }
            for(int j = i+1;j<array.size();j++)
            {
                if(other==array[j])
                {
                    mintt.push_back(array[i]*other);
                    numbers.push_back(array[i]);
                    break;
                }
            }
        }
        
        if(mintt.size()>=1)
        {
        int temp = 0;
        for(int i =1;i<mintt.size();i++)
            if(mintt[temp] > mintt[i])
                temp = i;
        
        result.push_back(numbers[temp]);
        result.push_back(sum-numbers[temp]);
        }
        return result;
    }
};
