#include <iostream>
#include <deque>
#include <algorithm>
#include <stdio.h>
using namespace std;

void print(int elem)
{
	cout << elem << ' ';
}
//逆向时就是把原来的位置向前移动一个，其他不变；不能超过所定义的区间
int main()
{
	deque<int> coll;

	for (int i=1; i<=9; ++i)
	{
		coll.push_back(i);
	}

	for_each(coll.begin(), coll.end(), print);
	cout << endl;

	deque<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 3);
	cout << *pos1 << endl;
	printf("%p\n", pos1);//没有对pos1重载，用C语言显示pos1是指针不需要重载
	deque<int>::iterator pos2;
	pos2 = find(coll.begin(), coll.end(), 7);
	cout << *pos2 << endl;

	for_each(pos1, pos2, print);
	cout << endl;

	deque<int>::reverse_iterator rpos1(pos1);
	cout << *rpos1 << endl;
	deque<int>::reverse_iterator rpos2(pos2);
	cout << *rpos2 << endl;

	for_each(rpos2, rpos1, print);
	cout << endl;

	//base()将逆向迭代器转回正常迭代器
	deque<int>::iterator rrpos1;
	rrpos1 = rpos1.base();
	cout << "Base()：" << *rrpos1 << endl;
	return 0;

}