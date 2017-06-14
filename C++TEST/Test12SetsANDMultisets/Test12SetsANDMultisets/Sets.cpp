#include <iostream>
#include <set>
using namespace std;

//Sets��Multisets���ܲ�ֻ࣬��Multisets�����ظ�Ԫ��
//lower_bound(elem) ���ش��ڵ���elem�ĵ�һ��Ԫ������λ��
//upper_bound(elem) ���ش���elem�ĵ�һ��Ԫ��λ��
//equal_range(elem) ���ؽ�lower_bound��upper_bound�ķ���ֵ����һ��pair��Ԫ������

//��lower_bound(elem)��equal_range.first����upper_bound(elem)��equal_range.second
//��Sets��Multisets�ڲ�������ͬ��ֵ��Ԫ��
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
	//typedef set<int, greater<int> > INTSET;//��������
	typedef multiset<int, greater<int> > INTSET;//��������

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
	//boolΪsecond��ʾ�����Ƿ�ɹ���firstΪ��Ԫ�ص�λ��
	pair<INTSET::iterator, bool> status = coll1.insert(4);
	if (status.second)
	{
		cout << "4 inserted as element "
			<< distance(coll1.begin(), status.first) + 1 //�������λ�õ���ͷλ�õľ���
			<< endl;
	}
	else
		cout << "4 already exists" << endl;
	*/
	//Multiset
	//Ԫ���ǿ����ظ��ģ����Բ���Ҫ�ж�
	INTSET::iterator ipos = coll1.insert(4);
	cout << "4 inserted as element "
		<< distance(coll1.begin(), ipos) + 1 //�������λ�õ���ͷλ�õľ���
		<< endl;
	//Ĭ��Ϊ��������
	//set<int> coll2(coll1.begin(), coll1.end());
	multiset<int> coll2(coll1.begin(), coll1.end());
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//�Ƴ���Ԫ��3֮ǰ������Ԫ��
	coll2.erase(coll2.begin(), coll2.find(3));

	int num;
	//�Ƴ�����Ԫ��Ϊ5��Ԫ��
	num = coll2.erase(5);
	cout << num << " elements removed" << endl;
	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}