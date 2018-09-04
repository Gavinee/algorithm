/*
  题目描述
  我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
//author = Qiufeng

class Solution {
public:
    int rectCover(int number) {
        vector<int> way;
        int temp;
        int i;
        if(number==0)
        {
            return 0;
        }
        
        for (i = 1; i <= number; i++)
	    {
            if (i == 1)
                way.push_back(1);
            else if (i == 2)
                way.push_back(2);
            else 
            {
                temp = way[way.size() - 1] + way[way.size() - 2];
                way.push_back(temp);
            }
	     }
        return way[way.size()-1];
    }
};
