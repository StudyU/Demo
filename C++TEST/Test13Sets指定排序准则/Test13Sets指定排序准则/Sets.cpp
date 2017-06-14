#include "algostuff.h"
#include <set>
#include <iostream>
using namespace std;

template <class T>
class RuntimeCmp
{
public:
	enum cmp_mode {normal, reverse};//升序和降序
private:
	cmp_mode mode;
public:
	RuntimeCmp(cmp_mode m=normal):mode(m) {}

	bool operator() (const T &t1, const T &t2)
	{
		return mode==normal ? t1<t2 : t2<t1;
	}

	bool operator== (const RuntimeCmp& rc)
	{
		return mode == rc.mode;
	}
};

typedef set<int, RuntimeCmp<int> > IntSet;
void fill(IntSet& set);

int main()
{
	IntSet coll1;
	fill(coll1);
	PRINT_ELEMENTS(coll1, "coll1: ");

	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);//降序排列

	IntSet coll2(reverse_order);
	fill(coll2);
	PRINT_ELEMENTS(coll2, "coll2: ");

	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1, "New coll1: ");

	if (coll1.value_comp() == coll2.value_comp())//比较coll1和coll2的排序准则是否相同
	{
		cout << "coll1 and coll2 have same sorting criterion"
			<< endl;
	}
	else
		cout << "coll1 and coll2 have different sorting criterion"
		<< endl;

	return 0;
}

void fill(IntSet& set)
{
	set.insert(4);
	set.insert(7);
	set.insert(5);
	set.insert(1);
	set.insert(6);
	set.insert(2);
	set.insert(5);
}