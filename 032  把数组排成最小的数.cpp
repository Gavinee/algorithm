/*
  题目描述
  输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小
  的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

//author = Qiufeng

/*
        思路：找出长度最长的数据，保存最长的数据的长度，记录着每个数据的长度。
        将每个数据都变成相同的长度：将每个数据拼接着数据除以10的余数的循环值。
        比较每个数据大小，从而进行原始数据排序
        将数字转换为字符串，利用字符串流来转换
        最后将数据进行拼接，输出。
*/

#include <string>
#include <sstream>

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
         vector<int> everyoneSize;
         vector<int> sort;     //
         int countMax = 0; 
         for(int i = 0;i<numbers.size();i++)      //找出最长的数字
         {
             int temp;
             int size = 0;
             temp = numbers[i];
             while(temp%10!=0 or temp/10!=0)
             {
                 temp /=10;
                 size++;
             }
             if(countMax<size)
                 countMax = size;
             sort.push_back(numbers[i]);
             everyoneSize.push_back(size);
         }
        
         AddPostfix(numbers,everyoneSize,countMax);
         Bubble(numbers,sort);

        string tt;
        
        for(int i = 0;i<sort.size();i++)
        {
            
            //下面的是利用字符串流进行数字转换为字符串，进行拼接。
            string res;
            stringstream ss;
            ss<<sort[i];
            ss>>res;
            tt+=res;
        }
        return tt;
    }
    
    void AddPostfix(vector<int> &numbers,vector<int> &everyoneSize,int maxSize)
    {
         for(int i = 0;i<numbers.size();i++)      //找出最长的数字
         {
             int addAll  =0;
             int cnt = 0;
             if(numbers[i]%10!=0)
                 cnt = numbers[i]%10;
             for(int j = everyoneSize[i];j < maxSize;j++)
             {
                 numbers[i]*=10;
                 addAll+=cnt;
                 cnt*=10;
             }
             numbers[i]+=addAll;
         }
    }
    
    void Bubble(vector<int> &numbers,vector<int> &sort)
    {
        for(int i = 0;i<numbers.size();i++)
         {
             for(int j = 0;j<numbers.size()-i-1;j++)
             {
                 if(numbers[j]>numbers[j+1])
                 {
                     int temp,temp1;
                     temp = numbers[j+1];         temp1 = sort[j+1];
                     numbers[j+1] = numbers[j];   sort[j+1] = sort[j];
                     numbers[j] = temp;           sort[j] = temp1;
                 }
             }
         }
    }
};
