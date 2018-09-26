#include<vector>
#include<iostream>

using namespace std;
vector<vector<int>> permuteUnique(vector<int>& nums);
void backdata(vector<int> nums, vector<int> temp, vector<vector<int>>& result);		//回溯
vector<vector<int>>  duplicateRemoval(vector<vector<int>> result);
bool ifexit(vector<vector<int>> temp,vector<int> cmt);

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<int> temp;
	vector<vector<int>> result;
	backdata(nums, temp, result);
	vector<vector<int>> result1;
	result1 = duplicateRemoval(result);
	return result1;
}

void backdata(vector<int> nums,vector<int> temp,vector<vector<int>>& result) {
	if (nums.size() == 0)
	{
		result.push_back(temp);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		vector<int> tt;
		for (int j = 0; j < nums.size(); j++)
		{
			if (i != j)
				tt.push_back(nums[j]);
			else
				temp.push_back(nums[j]);
		}
		backdata(tt,temp,result);
		temp.pop_back();
	}
}

vector<vector<int>> duplicateRemoval(vector<vector<int>> result)
{
	vector<vector<int>> temp;
	
	for (int i = 0; i < result.size(); i++)
	{
		if (!ifexit(temp, result[i]))
			temp.push_back(result[i]);
	}
	return temp;
}

bool ifexit(vector<vector<int>> temp,vector<int> cmt) {
	if (temp.size() == 0)
		return false;

	for (int i = 0; i < temp.size(); i++)
	{
		int count = 1;
		for (int j = 0; j < temp[0].size(); j++)
		{
			if (cmt[j] == temp[i][j])
			{
				if (count == temp[0].size()-1)
					return true;
				count++;
			}
		}
	}
	return false;
}

int main(void)
{
	vector<vector<int>> tty;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(6);

	tty = permuteUnique(nums);
	cout << tty.size() << "           " << endl;
	for (int i = 0; i < tty.size(); i++)
	{
		for (int j = 0; j < tty[i].size(); j++)
		{
			cout << tty[i][j];
		} 
		cout << endl;
	}

	system("pause");
	return 0;
}
