/*
  题目描述
  在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
  每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
  整数，判断数组中是否含有该整数。
*/
# author = Qiufeng

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int row = array.size();
        int col = array[0].size();
        for(int i = 0 ;i < row;i++)
        {
            for(int j = col-1;j >= 0;j--)
            {
                if(array[i][j] == target)
                    return true;
                if(array[i][j] < target)
                    break;
            }
        }
        return false;
    }
};








