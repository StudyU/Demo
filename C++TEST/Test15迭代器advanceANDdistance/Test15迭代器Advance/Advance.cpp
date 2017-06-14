//advance��distance����Random Access�������ǳ������Ӷȣ������������������Ը��Ӷ�

//ϣ�����ɸ��������͵��������࣬Ӧ��ʹ��advance��distance��������operator+=��operator-
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Advance() �ɽ���������λ�ã����ӵķ����в�������������ʹ������һ��ǰ��������ˣ����Ԫ��
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

	advance(pos, 3);//ǰ��3
	cout << *pos <<endl;

	advance(pos, -1);//����1
	cout << *pos <<endl;

	return 0;
}

//Distance�������������֮��ľ���
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

	//����
	if (pos!=coll.end())
	{
		cout << "Begin to Pos diatance: " 
			<< distance(coll.begin(), pos) << endl;
	}
	else
		cout << "Not find 5 value!" << endl;


	//����iter_swap
	iter_swap(coll.begin(), ++coll.begin());//���vectorΪ�������޷���������Ϊ++coll.begin()�õ�������ʱָ��
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}