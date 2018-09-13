/*
  题目描述
  把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因
  为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

//author = Qiufeng

/***************************超时程序*****************************************/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0)
        	return 0;
        if(index ==1)
            return 1;
        vector<int> tt;
        tt.push_back(1);

        FindNUgly(tt, index);
        return tt[index - 1];
    }

    void FindNUgly(vector<int> &tt, int index)
    {
        int temp = 2;
        while (tt.size() != index)
        {
            int i = temp;
            while (i != 1)
            {
                if(i % 2 == 0)
                    i /= 2;
                else if (i % 3 == 0)
                    i /= 3;
                else if (i % 5 == 0)
                    i /= 5;
                else
                    break;

                if (i == 1)
                {
                    tt.push_back(temp);
                    cout << temp<<endl;
                }
            }
            temp++;
        }
    }
};
