/*
  求target的1/2次方(根号target),
*/

//author = Qiufeng
//第一种方法想把范围缩放到1的大小再进行二分法。
//第二种方法则直接进行二分法。
//对于小数，方法一方法二的效率差不多
//但一旦输入数据变得很大，则方法二的效率要大于方法一的效率。
/****************************方法一***************************************/
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
double dichotomy(int target,double delta);
int main(void)
{
	double tt;
	int ttx = 101;
	double delta = 0.0001;
	tt = dichotomy(ttx,delta);
	cout << tt << endl;
	system("pause");
	return 0;
}

double dichotomy(int target,double delta)
{
	double value;
	double start, end;
	int i = 0;
	for (; i < target; i++)
	{
		if (i*i > target)
		{
			value = i*i;
			break;
		}
	}

	start = double(i - 1);
	end = double(i);
	double temp;
	while (abs(value - target) > delta)
	{
		temp = (start + end) / 2;
		value = temp*temp;
		if (value > target)
			end = temp;
		else
			start = temp;
	}
	return temp;
}


/*****************************方法二***********************************/
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
double dichotomy(int target,double delta);
int main(void)
{
	double tt;
	int ttx = 101;
	double delta = 0.0001;
	tt = dichotomy(ttx,delta);
	cout << tt << endl;
	system("pause");
	return 0;
}

double dichotomy(int target,double delta)
{
	double value;
	double start = 1, end = target;
	double temp;
	value = ((start + end) / 2)*((start + end) / 2);

	while (abs(value - target) > delta)
	{
		temp = (start + end) / 2;
		value = temp*temp;
		if (value > target)
			end = temp;
		else
			start = temp;
	}
	return temp;
}
