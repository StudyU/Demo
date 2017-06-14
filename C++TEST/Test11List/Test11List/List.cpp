#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printLists(const list<int> &l1, const list<int> &l2)
{
	cout << "List1:";
	copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "List2:";
	copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main()
{
	list<int> list1, list2;
	//赋值
	for (int i=0; i<6; ++i)
	{
		list1.push_back(i);//从头插入
		list2.push_front(i);//从尾部插入
	}
	printLists(list1, list2);

	//元素转移
	list2.splice(find(list2.begin(), list2.end(), 3), list1);
	printLists(list1, list2);

	//list2首尾互换
	list2.splice(list2.end(), list2, list2.begin());
	printLists(list1, list2);

	//排序
	list2.sort();
	list1 = list2;
	//唯一值显示
	list2.unique();
	printLists(list1, list2);
	
	//已序转移排序
	list1.merge(list2);
	printLists(list1, list2);

	//显示序列信息
	cout << "list1.maxsize:" << list1.max_size() << endl;
	cout << "list1.size:" << list1.size() << endl;
	cout << "list1.empty:" << list1.empty() << endl;

	return 0;

}