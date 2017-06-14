#include <iostream>
#include <set>
using namespace std;

//Sets和Multisets功能差不多，只是Multisets可以重复元素
//lower_bound(elem) 返回大于等于elem的第一个元素所处位置
//upper_bound(elem) 返回大于elem的第一个元素位置
//equal_range(elem) 返回将lower_bound和upper_bound的返回值做成一个pair的元素区间

//当lower_bound(elem)或equal_range.first等于upper_bound(elem)或equal_range.second
//则Sets和Multisets内不存在相同数值的元素
int main1()
{
	set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);
	
	cout << "lower_bound(3):" << *c.lower_bound(3) << endl;
	cout << "upper_bound(3):" << *c.upper_bound(3) << endl;
	cout << "equal_range(3):" << *c.equal_range(3).first << *c.equal_range(3).second << endl;

	cout << endl;

	cout << "lower_bound(5):" << *c.lower_bound(5) << endl;
	cout << "upper_bound(5):" << *c.upper_bound(5) << endl;
	cout << "equal_range(5):" << *c.equal_range(5).first << *c.equal_range(5).second << endl;

	return 0;
}

int main()
{
	//typedef set<int, greater<int> > INTSET;//降序排列
	typedef multiset<int, greater<int> > INTSET;//降序排列

	INTSET coll1;

	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);

	INTSET::iterator pos;
	for (pos=coll1.begin(); pos!=coll1.end(); ++pos)
	{
		cout << *pos << ' ';
	}
	cout << endl;

	//Sets
	/*
	//bool为second表示安插是否成功，first为新元素的位置
	pair<INTSET::iterator, bool> status = coll1.insert(4);
	if (status.second)
	{
		cout << "4 inserted as element "
			<< distance(coll1.begin(), status.first) + 1 //计算出新位置到开头位置的距离
			<< endl;
	}
	else
		cout << "4 already exists" << endl;
	*/
	//Multiset
	//元素是可以重复的，所以不需要判断
	INTSET::iterator ipos = coll1.insert(4);
	cout << "4 inserted as element "
		<< distance(coll1.begin(), ipos) + 1 //计算出新位置到开头位置的距离
		<< endl;
	//默认为升序排列
	//set<int> coll2(coll1.begin(), coll1.end());
	multiset<int> coll2(coll1.begin(), coll1.end());
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//移除，元素3之前的所有元素
	coll2.erase(coll2.begin(), coll2.find(3));

	int num;
	//移除所有元素为5的元素
	num = coll2.erase(5);
	cout << num << " elements removed" << endl;
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}