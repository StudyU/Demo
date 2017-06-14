//随机存取迭代器{对lists，maps，sets无效}
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

	//每隔2个输出
	for (pos=coll.begin(); pos<coll.end()-1; pos +=2)
	{
		cout << *pos << ' ';
	}
	cout << endl;
}