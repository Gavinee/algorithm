/*
  题目描述
  请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中
  的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了
  矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4
  矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了
  矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

//author = Qiufeng

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<vector<char>> tt;        //将数组转换为二维向量形式
        vector<char> temp;              //中间向量
        vector<vector<int>> index;              //已走过的路径
        vector<vector<int>> find;       //寻找首个元素放置的位置
        vector<char> strr;				//将字符串数组用向量表示

        for (int i = 0; i < rows; i++)
        {
            vector<char> cl;
            for (int j = 0; j < cols; j++)
            {

                cl.push_back(matrix[i*cols+j]);
                if (j == cols - 1)
                {
                    tt.push_back(cl);
                }
            }
        }


        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (tt[i][j] == str[0])
                {
                    vector<int> ql;
                    ql.push_back(i);
                    ql.push_back(j);
                    find.push_back(ql);
                    continue;
                }
                if (i == rows - 1 && j == cols - 1)
                {
                    if (find.size() == 0)
                        return false;
                }
            }
        }

        int k = 0;
        while (str[k] != '\0')
        {
            strr.push_back(str[k]);
            k++;
        }

        for (int i = 0; i < find.size(); i++)
        {
            if (Path(tt, strr, find[i][0], find[i][1], index, 0))
                break;
            if (i == find.size() - 1)
                return false;
        }
        return true;

    }

    bool Path(vector<vector<char>> tt, vector<char> strr, int i, int j, vector<vector<int>> index,int nums)
    {
        int rows = tt.size();
        int cols = tt[0].size();

        if (i < 0 || j < 0||i>=rows||j>=cols)
            return false;


        if (tt[i][j] != strr[nums])
            return false;

        if (index.empty())
        {
            vector<int> New;
            New.push_back(i);
            New.push_back(j);
            index.push_back(New);
        }

        for (int k = 0; k < index.size(); k++)
        {

            if(index.size()>1)
                if (index[k][0] == i && index[k][1] == j)
                    return false;

            if (k == index.size() - 1)
            {
                    vector<int> New;
                    New.push_back(i);
                    New.push_back(j);
                    index.push_back(New);

                if (nums == strr.size() - 1)
                    return true;

                if (Path(tt, strr, i - 1, j, index, nums + 1) || Path(tt, strr, i + 1, j, index, nums + 1)
                    || Path(tt, strr, i, j - 1, index, nums + 1) || Path(tt, strr, i, j + 1, index, nums + 1))
                {
                    return true;
                }
                else
                    return false;
            }
        }
        return false;
    }
};
