#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	typedef map<string, float> StringFloatMap;
	StringFloatMap coll;

	//按数字<部分特殊字符(空格，*，%等)<字母（首字母排序（A<Z<a<z））
	coll["VAT"] = 0.15;
	coll["Pi"] = 3.1415;
	coll["an arbitrary number"] = 4983.223;
	coll["Null"] = 0;

	StringFloatMap::iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos)
	{
		cout << "key: \""<< pos->first << "\" "
			<< "value: " << pos->second << endl;
	}
}
