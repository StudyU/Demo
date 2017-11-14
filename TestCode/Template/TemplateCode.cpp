#include <stdio.h>
#include <string>
using namespace std;
/*
Function templates 可以针对不同的 template arguments 定义一整族（a family of）函数。
Function templates 将依照传递而来的自变量（arguments）的类型而被实例化（instantiated）。16
你可以明确指出 template parameters。
Function templates 可以被重载（overloaded）。
重载 function templates 时，不同的重载形式之间最好只存在「绝对必要的差异」。
请确保所有形式的重载函数都被写在它们的被调用点之前。

1. 把两个自变量转型为相同类型：
max(static_cast<double>(4), 4.2); // OK
2. 明确指定 T的类型：
max<double>(4, 4.2);

重载函数模板：non-template function(常规函数) 可以和同名的 function template(函数模板) 共存，也可以和其相同类型
的具现体共存。当其它要素都相等时，重载解析机制会优先选择 non-template function，而不选
择由 function template 实例化后的函数实体

所有重载函数都使用by reference方式来传递自变量，类型要相同
总是把所有形式的重载函数写在它们被调用之前。
*/
/********************************重载函数模板*********************************/
//non-template function A
inline int const& Max(int const& a, int const& b)
{
	return a > b ? a : b;
}

// function template A1，引用
template <typename T> 
inline T const& Max(T const& a, T const& b)
{
	return a > b ? a : b;
}

// 传值，但是会带来不必要的拷贝
template <typename T>
inline T const Max1(T const a, T const b)
{
	return a > b ? a : b;
}

// function template A2
template <typename T>
inline T const& Max(T const& a, T const& b, T const& c)
{
	return Max(::Max(a, b), c);
}

int main1()
{
	int i = 1;
	int j = 2;
	string str1 = "hh";
	string str2 = "2231";
	int k = ::Max(i, j);// A
	int kk = ::Max<>(i, j);// A1
	int kkk = ::Max(i, j, 3);// A2
	string str = ::Max(str1, str2);// A2
								   //::Max("ssw", "hig1");	// 错误，引用传值字符串字面长度不同，底层的array类型就不同
	::Max1("ssw", "hig1");	// 传值,退化为相同类型，只有当你以 by value 方式使用字符串字面常数（string literals）时，字符串底部的 array 才
							// 会被转 型（退化）为一个字符指针（也就是发生 "array-to-pointer" 转换）。
	return 0;
}
/********************************重载函数模板*********************************/

/********************************模板参数*********************************/
/*
1. local classes 和 local enum types（亦即声明于函数定义内部的 classes 和 enums）
不能做为template type arguments 使用。
2. 如果某个 type 涉及无名的（unnamed）class types 或无名的（unnamed）enum types，这样的 type
不能做为 template type arguments 使用； 但如果运用 typedef使其具名， 便可用做 template
type arguments。
*/

template <typename T>
class List
{

};

// typedef使某个 unnamed type 有了名称
typedef struct
{
	float x;
	float y;
} Point;

typedef enum ne {red, greed, blue} *ColorPtr;

int main2()
{
	//译注：这是一个定义于函数内部的所谓 local type
	struct Asso
	{
		int* p;
		int* q;
	};

	List<Asso*> error1;	// ERROR： template argument 不能是个 local type
	List<ColorPtr> error2;	// ERROR： template argument 不能是个 unnamed type
	List<Point> OK;			// OK：原本无名的 type 因 typedef而有了名称

	return 0;
}

template <typename T>
void clear(T p)
{
//	*p = 0;	// unary operator* 必须可施行于 T身上
}

int main3()
{
	int i = 1;
	clear(i);	// ERROR： int并不支持 unary operator*

	return 0;
}

template <typename T, T nontype_param>
class C;

class Base {
public:
	int i;
} base;

class Derived : public Base
{

} derObj;

int main()
{
	Base* p = new Base();
	p->i = 1;
	C<Base*, &base>* k;		// ok
	//C<Base*, &derObj>* kk;	// ERROR：「derived-to-base 转换」不被考虑
	//C<int, p->i>* hh;		// ERROR：成员变数不被考虑

	//int a[10];
	//C<int*, a[0]>* gg;		// ERROR：不能使用 array内某个元素的地址
	return 0;
}

/********************************模板参数*********************************/

