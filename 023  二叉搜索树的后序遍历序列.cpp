/*
  题目描述
  输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入
  的数组的任意两个数字都互不相同。
*/

//author = Qiufeng
//参考博客园：wanglei5205   链接：http://www.cnblogs.com/wanglei5205/p/8684408.html

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		return Subtree(sequence, 0, sequence.size() - 1);
	}

	bool Subtree(vector<int> subsequence, int begin, int end) {
		//边界条件
		if (subsequence.empty() || begin > end)
			return false;

		//划分左右子树，并判断左右子树和根节点的关系
		int  i = begin;
		for (; i < end; ++i)
			if (subsequence[i] > subsequence[end])
				break;

		int j = i;
		for (; j < end; ++j)
			if (subsequence[j] < subsequence[end])
				return false;
		
		//判断左子树是不是二叉搜索树
		bool left = true;
		if (i > begin)
			left = Subtree(subsequence, begin, i - 1);

		//判断右子树是不是二叉搜索树
		bool right = true;
		if (i < end - 1)
			right = Subtree(subsequence, i, end - 1);
		return left&&right;
	}
};

