/*
      求二元一次方程组的两个参数.
      y = a1x*a2
      
      测试用例:
      输入:
          3
          1 2 3 4 5 9
          1 2 3 4 5 6
          1 2 3 3 6 9
          
       输出:
          1 1
          UNKNOWN
          UNKNOWN
      
*/

//author = Qiufeng
//笔试只有40%通过了，规模在[1,100],以下代码修改了下，但是应该也
只50%能通过，暴力解法只能保证小数能通过，要想100%这要用别的办法。

#include <iostream>
#include<vector>
using namespace std;


vector<long> buy(long a1,long b1,long v1,long a2,long b2,long v2)
{
	vector<long> tt;
	int count = 0;

	for (int i = -100; i < 100; i++)
	{
		for (int j = -100; j < 100; j++)
		{
			if ((a1*i + b1*j == v1) &&( a2*i + b2*j == v2))
			{
				if (count > 1)
				{
					vector<long> temp;
					temp.push_back(0);
					return temp;
				}
				tt.push_back(i);
				tt.push_back(j);
				count++;
			}
		}
	}
	if (tt.empty())
		tt.push_back(0);

	if (tt[0] <= 0 || tt[1] <= 0)
	{
		vector<long> temp;
		temp.push_back(0);
		return temp;
	}

	return tt;
}

int main() {
	int tt;
	cin >> tt;
	int i = 0;
	vector<vector<long>> q;
	while (i < tt)
	{
		long a1, b1, v1, a2, b2, v2;
		cin >> a1 >> b1 >> v1 >> a2 >> b2 >> v2;
		vector<long> p;
		p = buy(a1, b1, v1, a2, b2, v2);
		q.push_back(p);
		i++;
	}

	for (int i = 0; i < q.size(); i++)
	{
		if (q[i].size()==1)
			cout << "UNKNOWN" << endl;
		else
			cout << q[i][0] << " " << q[i][1] << endl;
	}

	//system("pause");
	return 0;
}





