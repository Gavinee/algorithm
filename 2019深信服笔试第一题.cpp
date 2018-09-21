/*
    挡板问题:
        从左到右放置n个挡板，相邻两个挡板的间隔是1m，用来导流，若最左最右的挡板比较低，
        这水会溢出。若两较高的挡板中间有较低的挡板，则会淹没较低的挡板。若挡板依次是非
        递增或非递减的，这挡板之间的水流是两两独立的。求n个挡板一共能拦住多少m^2的水。
        
    测试用例：
        输入：
          2       //两组数据
          3       //挡板个数  
          1 3 2   //各个挡板的高度
          3       //挡板个数
          3 2 5   //各个挡板的高度
          
        输出:
          3       //第一组挡板说拦住的水的立方数
          6       //第二组挡板说拦住的水的立方数
        
*/
//正确的程序，可惜当时没有运行出来，但是思路是对的，
//我在笔试完之后继续coding出来的,可能我的方法太麻烦，
//有更好的方法， 
//author = Qiufeng

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int ss(vector<int> temp);
int ss(vector<int> temp)
{
	int Sum = 0;

	vector<int> distinst;
	vector<int> dis;
	distinst.push_back(temp[0]);
	dis.push_back(0);
	int cnt = 0;
	for (int i = 1; i < temp.size(); i++)
	{
		if (temp[cnt] <= temp[i])
		{
			cnt = i;
			distinst.push_back(temp[cnt]);
			dis.push_back(cnt);
		}
	}

	int cmt = temp.size() - 1;
	if (dis[dis.size() - 1] < temp.size() - 1)
	{

		stack<int> dist;
		stack<int> di;

		for (int j = temp.size()-1; j >dis[dis.size() - 1]; j--)
		{
			if (temp[cmt] <= temp[j])
			{
				cmt = j;
				dist.push(temp[cmt]);
				di.push(cmt);
			}
		}

		while (!dist.empty())
		{
			distinst.push_back(dist.top());
			dis.push_back(di.top());
			dist.pop();
			di.pop();
		}
	}

	for (int s = 0; s < distinst.size()-1; s++)
	{
		if (distinst[s] < distinst[s + 1])
		{
			Sum += distinst[s] * (dis[s + 1] - dis[s]);
			//cout << distinst[s]<<"     "<<dis[s+1] -dis[s]<<"    "<<Sum<<"    "<<endl;
		}
		else
		{
			Sum += distinst[s + 1] * (dis[s + 1] - dis[s]);
			//cout << distinst[s] << "     " << dis[s + 1]  << "    " << dis[s]<< "      "<<Sum << "    " << endl;
		}
	}
	return Sum;
}

int main() {
	int tt;
	int count;
	cin >> count;
	
	int j = 0;

	vector<int>  qq;

	while (j < count) 
	{	
		vector<int> temp;
		int i = 0;
		int f;
		cin >> tt;
		while (i < tt)
		{
			cin >> f;
			temp.push_back(f);
			i++;
		}
		qq.push_back(ss(temp));
		j++;
	}

	for (int k = 0; k < qq.size(); k++)
		cout << qq[k] << endl;

	return 0;
}
