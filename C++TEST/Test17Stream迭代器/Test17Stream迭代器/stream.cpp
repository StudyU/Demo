#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//每隔三个string输出
int main()
{
	istream_iterator<string> cinPos(cin);
	ostream_iterator<string> coutPos(cout, " ");

	while (cinPos!=istream_iterator<string>())
	{
		advance(cinPos, 2);
		if (cinPos!=istream_iterator<string>())
		{
			*coutPos++ = *cinPos++;
		}
	}

	return 0;
}