/*
  有两个字符串str1,str2,二者有且只有一个公共子序列，打印公共子序列。
*/

//author = Qiufeng

//利用递归求公共子序列
//vs2017中运行程序

#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
string son(string tt, string ss);
int main(void)
{
	string str1 = "abcdefghig";
	string str2 = "acdfgsgsgegsggig";
	string tt;
	tt = son(str1, str2);
	cout << tt.c_str() << endl;             //将字符串用输入输出流输出.   string.c_str()
	system("pause");
	return 0;
}

string son(string tt, string ss)
{
	string str="";
	int tempi,tempj;

	for (int i = 0; i < tt.length(); i++)
	{
		for (int j = 0; j < ss.length(); j++)
		{
			if (tt[i] == ss[j])
			{
				tempi = i;
				tempj = j;
				str = tt[tempi];
				return str += son(tt.substr(i+1, tt.length() - i - 1), ss.substr(j+1, ss.length() - j - 1));  
                //string.substr(pos,len)   pos : 当前位置          len :  字串长度
			}
		}
	}
	return str;
}




