//�����ȡ������{��lists��maps��sets��Ч}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> coll;
	for (int i=-3; i<=9; ++i)
	{
		coll.push_back(i);
	}

	cout << "Numbers/Distance: " << coll.end() - coll.begin() << endl;

	//uses < instead of !=
	vector<int>::iterator pos;
	for (pos=coll.begin(); pos<coll.end(); ++pos)
	{
		cout << *pos << ' ';
	}
	cout << endl;

	//uses [] instead of *
	for (int i=0; i<coll.size(); ++i)
	{
		cout << coll.begin()[i] << ' ';
	}
	cout << endl;

	//ÿ��2�����
	for (pos=coll.begin(); pos<coll.end()-1; pos +=2)
	{
		cout << *pos << ' ';
	}
	cout << endl;
}