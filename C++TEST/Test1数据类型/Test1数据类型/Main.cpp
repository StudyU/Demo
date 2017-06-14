#include <iostream>
//2个头文件预定义了各种数据类型的最大小值
#include <climits> 
#include <cfloat>

using namespace std;
int main()
{
	//int i;
	//short j;
	//long k;
	//float ii;
	//double jj;
	//long double kk;

	unsigned int i = -1;
	int j = 256;
	cout << "kk:" << i % j << endl;
	system("pause");
	cout << "int i: (" << INT_MIN << "--" << INT_MAX << ")" << endl;
	cout << "short j: (" << SHRT_MIN << "--" << SHRT_MAX << ")" << endl;
	cout << "long k: (" << LONG_MIN << "--" << LONG_MAX << ")" << endl;
	cout << "float ii: (" << FLT_MIN << "--" << FLT_MAX << ")" << endl;
	cout << "double jj: (" << DBL_MIN << "--" << DBL_MAX << ")" << endl;
	cout << "long double kk: (" << LDBL_MIN << "--" << LDBL_MAX << ")" << endl;
	
	return 0;
}
//
//#include <boost/lexical_cast.hpp>     
//#include <iostream>     
//using namespace std;
//int main()
//{
//	using boost::lexical_cast;
//	int a = lexical_cast<int>("123");
//	double b = lexical_cast<double>("123.0123456789");
//	string s0 = lexical_cast<string>(a);
//	string s1 = lexical_cast<string>(b);
//	cout << "number: " << a << "  " << b << endl;
//	cout << "string: " << s0 << "  " << s1 << endl;
//	int c = 0;
//	try {
//		c = lexical_cast<int>("abcd");
//	}
//	catch (boost::bad_lexical_cast& e) {
//		cout << e.what() << endl;
//	}
//
//	system("pause");
//	return 0;
//}
