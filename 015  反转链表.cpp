/*
  题目描述
  输入一个链表，反转链表后，输出新链表的表头。
*/

//author = Qiufeng

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {            //将链表所指的方向依次倒置。
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNode = pHead;
        ListNode* pPrev = NULL;
        while(pNode!=NULL)
        {
            ListNode* pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pPrev;
    }
};


/**************************************原来不清楚的地方用实例来说明******************************/
#include<iostream>

using namespace std;
int main(void)
{
	int* a; 
	int* b;
	int c=2;
	int d = 5;

	cout << "c的地址值:" << &c << endl;
	a = &c;  //a就是c的地址
	cout<<"a的地址值:" << a << endl;
	b = a;	 //b就是a的地址，也就是b就是c的地址。
	cout <<"b的地址值:"<< b << endl;
	d = *b;  //d的值直接指向b上地址上的值，也就是a上地址上的值，即c上地址上的值,在python中是深拷贝copy.deepcopy()。
	cout << "d的地址值:" << &d << endl;
	//最后d直接赋值为c。中间的指针发生改变，对结果没有影响。
	*a = 4;  //将指针b的地址指向4的位置。
	cout << "a的地址值:" << a << endl;
	*b = 3;  //将指针b的地址指向3的位置。
	cout << "*a的值为：" << *a << endl;
	cout << "*b的值为:" << *b << endl;
	cout << "c的值为:" << c << endl;
	cout <<"d的值为:"<< d<<endl;
	cout << "b的地址值:" << b << endl;

	system("pause");
	return 0;
}

/*
输出：
		c的地址值:00AFFD50
		a的地址值:00AFFD50
		b的地址值:00AFFD50
		d的地址值:00AFFD4C
		a的地址值:00AFFD50
		*a的值为：3
		*b的值为:3
		d的值为:2
		b的地址值:00AFFD50
		请按任意键继续. . .
*/

//结论：不管指针是否指向指针还是值的地址，最后的指针的地址永远是在值的地址。指针只不过是给这个地址起了一个别名而已。
//若改变指针的地址上的值，就是改变了最后值的值。
