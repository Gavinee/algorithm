/*
  题目描述
  给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果
  输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他
  们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有
  以下6个:{[2,3,4],2,6,2,5,1},{2,[3,4,2],6,2,5,1}, {2,3,[4,2,6],2,5,1},
  {2,3,4,[2,6,2],5,1},{2,3,4,2,[6,2,5],1},{2,3,4,2,6,[2,5,1]}。
*/

//author = Qiufeng

#include <iostream>
#include<vector>
//#include<stack>
#include<queue>
using namespace std;

int FindMax(queue<int> tt);
vector<int> maxInWindows(const vector<int>& num, unsigned int size);

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	queue<int> tt;
	vector<int> MaxSequence;

	if (num.size() <= 0 || size<1)
		return MaxSequence;

	int j=0;
	while (j < size)
	{
		tt.push(num[j]);
		//cout << tt.back()<<"--------------"<<endl;
		j++;
	}

	for (int i = size; i <=num.size() ; i++)
	{
		MaxSequence.push_back(FindMax(tt));
		//cout << MaxSequence[MaxSequence.size() - 1] << endl;
		if (i < num.size())
		{
			tt.push(num[i]);
			tt.pop();
		}
	}
	return MaxSequence;
}


int FindMax(queue<int> tt)
{
	int temp = tt.front();
	tt.pop();
	while (!tt.empty())
	{
		if (temp < tt.front())
			temp = tt.front();
		tt.pop();
	}
	return temp;
}

int main(void)
{
	vector<int> num;
	int size = 3;
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(2);
	num.push_back(6);
	num.push_back(2);
	num.push_back(5);
	num.push_back(1);
	maxInWindows(num, size);
	system("pause");
	return 0;
}
