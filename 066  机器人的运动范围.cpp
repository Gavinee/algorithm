/*
  题目描述
  地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向
  左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k
  的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
  但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多
  少个格子？
*/

//author = Qiufeng

/*********************************在VS上能运行的程序************************************************************/

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int Sum(int tempSum);
int movingCount(int threshold, int rows, int cols);
bool movingPath(int threshold, int rows, int cols, vector<vector<int>> &tt, int targetRows, int targetCols);

int movingCount(int threshold, int rows, int cols)
{
	vector<vector<int>> tt;

	movingPath(threshold, rows, cols, tt, 0, 0);
	if (tt.empty())
		return 0;
	else
		return tt.size()-1;
}

bool movingPath(int threshold, int rows, int cols, vector<vector<int>> &tt,int targetRows,int targetCols)
{
	if (targetRows < 0 || targetCols < 0 || targetRows >= rows || targetCols >= cols)
		return false;

	int value = 0;
	value += Sum(targetRows);
	value += Sum(targetCols);
	//cout << targetRows << "--------------------" << targetCols << "--------"<<value<<endl;

	if (value > threshold)
		return false;

	if (tt.empty())
	{
		vector<int> New;
		New.push_back(targetRows);
		New.push_back(targetCols);
		tt.push_back(New);
		//cout << tt[0][0] << "          " << tt[0][1] << endl;
	}

	for (int i = 0; i < tt.size(); i++)
	{
		
		if (targetRows == tt[i][0] && targetCols == tt[i][1])
			if (tt.size() != 1)
			{
				return false;
			}

		if(i==tt.size()-1)
		{
				vector<int> New;
				New.push_back(targetRows);
				New.push_back(targetCols);
				tt.push_back(New);
				cout << targetRows << "          " << targetCols << endl;

			bool left = movingPath(threshold, rows, cols, tt, targetRows - 1, targetCols);
			bool right = movingPath(threshold, rows, cols, tt, targetRows + 1, targetCols);
			bool under = movingPath(threshold, rows, cols, tt, targetRows, targetCols - 1);
			bool on = movingPath(threshold, rows, cols, tt, targetRows, targetCols + 1);
			if (left || right || under || on)
				return true;
			else
				return false;
		}
	}
}

int Sum(int tempSum)
{
	int value = 0;
	while (tempSum % 10 || tempSum / 10)
	{
		value += tempSum % 10;
		tempSum /= 10;
	}
	return value;
}


int main(void)
{
	int threshold = 20;
	int rows = 100;
	int cols = 100;
	int q = movingCount(threshold, rows, cols);
	cout << q << endl;
	system("pause");
	return 0;
}
