#include<vector>
#include<iostream>

using namespace std;
void backdata(vector<int> nums, vector<int> temp, vector<vector<int>>& result);
vector<vector<int>> permuteUnique(vector<int>& nums);

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<int> temp;
	vector<vector<int>> result;
	backdata(nums, temp, result);

	//去重

	return result;
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
				tt.push_back(nums[i]);
			else
				temp.push_back(nums[i]);
		}
		backdata(tt,temp,result);
	}
}

int main(void)
{
	vector<vector<int>> tty;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(6);

	tty = permuteUnique(nums);
	cout << tty.size() <<"              "<< tty[0].size() << endl;

	for (int i = 0; i < tty.size(); i++)
	{
		for (int j = 0; j < tty[0].size(); j++)
		{
			cout << tty[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
