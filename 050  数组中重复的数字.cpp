/*
  题目描述
  在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但
  不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的
  数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复
  的数字2。
*/

//author = Qiufeng

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> tt;
        vector<int> count;
        if(length==0)
            return false;
        tt.push_back(numbers[0]);
        count.push_back(1);
        
        FindNums(numbers,length,tt,count);
        
        for(int i =0 ;i<count.size();i++)
        {
            if(count[i]>1)
            {
                *duplication = tt[i];
                return true;
            }
        }
        return false;
    }
    
     void FindNums(int numbers[],int length,vector<int> &tt,vector<int> &count)
    {
        for(int i =1;i<length;i++)
        {
            for(int j = 0;j<tt.size();j++)
            {
                if(tt[j]==numbers[i])
                {
                    count[j]++;
                    break;
                }
                if(j==tt.size()-1 and tt[j]!=numbers[i])
                {
                    tt.push_back(numbers[i]);
                    count.push_back(1);
                    break;
                }
            }
        }
    }
};
