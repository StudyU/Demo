//advance和distance对于Random Access迭代器是常数复杂度，对于其他类型是线性复杂度

//希望轻松更换容器和迭代器种类，应该使用advance和distance，而不是operator+=和operator-
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Advance() 可将迭代器的位置，增加的幅度有参数决定，可以使迭代器一次前进（或后退）多个元素
int main1()
{
	list<int> coll;
	for (int i=1; i<=9; ++i)
	{
		coll.push_back(i);
	}
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	list<int>::iterator pos = coll.begin();
	cout << *pos <<endl;

	advance(pos, 3);//前进3
	cout << *pos <<endl;

	advance(pos, -1);//后退1
	cout << *pos <<endl;

	return 0;
}

//Distance用来处理迭代器之间的距离
int main()
{
	list<int> coll;
	for (int i=-3; i<=9; ++i)
	{
		coll.push_back(i);
	}
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	//距离
	if (pos!=coll.end())
	{
		cout << "Begin to Pos diatance: " 
			<< distance(coll.begin(), pos) << endl;
	}
	else
		cout << "Not find 5 value!" << endl;


	//交换iter_swap
	iter_swap(coll.begin(), ++coll.begin());//如果vector为容器，无法运作，因为++coll.begin()得到的是暂时指针
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}