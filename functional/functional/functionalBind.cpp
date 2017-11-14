#define _CRT_SECURE_NO_WARNINGS

/*
function模板类和bind模板函数，使用它们可以实现类似函数指针的功能，但却却比函数指针更加灵活，特别是函数指向类 的非静态成员函数时。
std::function可以绑定到全局函数/类静态成员函数(类静态成员函数与全局函数没有区别),如果要绑定到类的非静态成员函数，则需要使用std::bind
*/
/*
#include <iostream>  
#include <functional>  
using namespace std;

typedef std::function<void()> fp;
void g_fun()
{
	cout << "g_fun()" << endl;
}
class A
{
public:
	static void A_fun_static()
	{
		cout << "A_fun_static()" << endl;
	}
	void A_fun()
	{
		cout << "A_fun()" << endl;
	}
	void A_fun_int(int i)
	{
		cout << "A_fun_int() " << i << endl;
	}

	//非静态类成员，因为含有this指针，所以需要使用bind  
	void init()
	{
		fp fp1 = std::bind(&A::A_fun, this);
		fp1();
	}

	void init2()
	{
		typedef std::function<void(int)> fpi;
		//对于参数要使用占位符 std::placeholders::_1  
		fpi f = std::bind(&A::A_fun_int, this, std::placeholders::_1);
		f(5);
	}
};
int main()
{
	//绑定到全局函数  
	fp f2 = fp(&g_fun);
	f2();

	//绑定到类静态成员函数  
	fp f1 = fp(&A::A_fun_static);
	f1();

	A().init();
	A().init2();
	return 0;
}
*/
/*
#include <iostream>
#include <functional>
#include <windows.h>
using namespace std;

typedef std::function<void()> fp;

class A
{
public:
virtual void f()
{
cout << "A::f()" << endl;
}

void init()
{
//std::bind可以表现出多态行为
fp f = std::bind(&A::f, this);
f();
}
};

class B :public A
{
public:
virtual void f()
{
cout << "B::f()" << endl;
}
};

int main()
{
A* pa = new B;
pa->init();

system("pause");
return 0;
}
*/

#include <random>
#include <iostream>
#include <functional>
#include <windows.h>
#include <time.h>
using namespace std;

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
	return n1;
}

struct Foo {
	void print_sum(int n1, int n2)
	{
		std::cout << n1 + n2 << '\n';
	}
	int data = 10;
};

class utils
{
public:
	utils(const char* name)
	{
		strcpy(_name, name);
	}

	static int GetID()
	{
		return 1;
	}

	void GetCallName( const char* name)
	{
		cout << _name << ": call name: " << name << endl;
	}

private:
	char _name[32];
};

int main()
{
	using namespace std::placeholders;

	// demonstrates argument reordering and pass-by-reference
	int n = 7;
	// 全局函数 只取参数2，1；
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused

	// nested bind subexpressions share the placeholders
	auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);// 只取参数3
	f2(10, 11, 12);

	// common use case: binding a RNG with a distribution
	std::default_random_engine e(time(0));//随机种子随时间变化
	std::uniform_int_distribution<> d(0, 10);
	std::function<int()> rnd = std::bind(d, e);
	for (int n = 0; n<10; ++n)
		std::cout << rnd() << ' ';
	std::cout << '\n';

	// bind to a member function
	Foo foo;
	auto f3 = std::bind(&Foo::print_sum, foo, 95, _1);
	f3(5);

	// bind to member data
	auto f4 = std::bind(&Foo::data, _1);
	std::cout << f4(foo) << '\n';

	//非静态成员函数
	utils util("Hello");
	auto f5 = std::bind(&utils::GetCallName, util, std::placeholders::_1);
	f5("Yudl");
	// 静态成员函数
	auto f6 = std::bind(&utils::GetID);
	cout << f6() << endl;

	system("pause");
	return 0;
}