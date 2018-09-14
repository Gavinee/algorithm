/*
  将两非降序排列的数组合并到其中一个数组中去
*/

//author = Qiufeng

/*************************方法一，未优化******************************/
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
vector<int> Merge_sort(vector<int> &tt, vector<int> ss);
int main(void)
{
	vector<int> tt;
	vector<int> ss;
	
	tt.push_back(2);
	tt.push_back(4);
	tt.push_back(6);
	tt.push_back(8);
	tt.push_back(9);
	
	ss.push_back(2);
	ss.push_back(2);
	ss.push_back(2);
	ss.push_back(2);
	ss.push_back(3);
	ss.push_back(4);

	tt = Merge_sort(tt, ss);

	for (int i = 0; i < tt.size(); i++)
	{
		cout << tt[i] << endl;
	}

	system("pause");
	return 0;
}

vector<int> Merge_sort(vector<int> &tt, vector<int> ss)
{
	int temp = 0;
	for (int i = 0; i < tt.size(); i++)
	{
		for (int j = temp; j < ss.size(); j++)
		{
			if (tt[i] >= ss[j])
			{
				tt.push_back(0);
				int k = tt.size() - 1;
				while (k >= i + 1)
				{
					tt[k] = tt[k - 1];
					k--;
				}
				tt[i] = ss[j];
				temp = j+1;
				i++;
			}
			else
			{
				if (i == tt.size() - 1)
				{
					int p = j;
					while (p <= ss.size() - 1)
					{
						tt.push_back(ss[p]);
						p++;
					}
					return tt;
				}
			}
		}
	}
	if (tt.size() != 0)
		return tt;
	else
		return ss;
}
