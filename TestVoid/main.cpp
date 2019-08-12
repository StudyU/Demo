#include <iostream>
#include <string>
#include "FunctionTraits.h"
#include <type_traits>
#include "GM.h"
#include "FunctionInvoke.h"

GMethodCreator::MapMethod GMethodCreator::m_mapMethod;

template<typename T>
void printType()
{
	std::cout << typeid(T).name() << std::endl;
}

float (*func)(std::string, int);
float func2(const std::string& str, int b)
{
	return static_cast<float>(str.size() + b);
}

struct AA
{
	int func(int& a, const int b) volatile { return a + b; }
	int operator()(int) const { return 0; }
};


int test1(int i)
{
	std::cout << i << std::endl;

	return 0;
}

void test2()
{
	std::cout << "test2" << std::endl;
}

double test3(std::string j, std::string str, std::string f)
{
	std::cout << j << std::endl;
	std::cout << str << std::endl;
	std::cout << f << std::endl;
	return 0.0;
}

class A
{
public:
	int test(int i)
	{
		std::cout << i << std::endl;
		return 0;
	}

	static int test21(float x)
	{
		std::cout << "static A::test2" << x << std::endl;
		return 0;
	}

	int test3(int i, std::string y)
	{
		std::cout << i << y << std::endl;
		return 0;
	}
};

int main()
{
	std::function<int(int)> f = [](int a) {return a; };
	printType<FunctionTraits<std::function<int(int)>>::functionType>();
	printType<FunctionTraits<std::function<int(int)>>::args<0>::type>();
	printType<FunctionTraits<std::function<int(int)>>::returnType>();
	std::cout << "count: " << FunctionTraits<std::function<int(int)>>::arity << std::endl;

	printType<FunctionTraits<decltype(f)>::functionType>();
	printType<FunctionTraits<decltype(func)>::functionType>();
	printType<FunctionTraits<decltype(func2)>::functionType>();
	printType<FunctionTraits<AA>::functionType>();
	printType<decltype(&AA::func)>();
	printType<FunctionTraits<decltype(&AA::func)>::functionType>();
	printType<FunctionTraits<decltype(&AA::func)>::args<0>::type>();
	printType<FunctionTraits<decltype(&AA::func)>::args<1>::type>();

	int n = FunctionTraits<decltype(&AA::func)>::arity;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "std::decay" << std::is_same<int, std::decay<FunctionTraits<decltype(&AA::func)>::args<0>::type>::type>::value << std::endl;
		std::cout << "std::decay no " << std::is_same<int, FunctionTraits<decltype(&AA::func)>::args<0>::type>::value << std::endl;

		if (std::is_same<int, std::decay<FunctionTraits<decltype(&AA::func)>::args<0>::type>::type>::value)
		{
			std::cout << "int" << std::endl;
		}
		
		if (std::is_same<const int, FunctionTraits<decltype(&AA::func)>::args<0>::type>::value)
		{
			std::cout << "other int" << std::endl;
		}

		if (std::is_same<int&, FunctionTraits<decltype(&AA::func)>::args<0>::type>::value)
		{
			std::cout << "other int" << std::endl;
		}
	}

	ADD_GM_METHOD(test1);
	ADD_GM_METHOD(test2);
	ADD_GM_METHOD(test3);
	ADD_GM_METHOD(A::test21);
	A a;
	ADD_GM_METHOD_OBJ(A::test3, &a);

	std::string i("89");
	VEC_STRING vecArgs;
	vecArgs.push_back(i);

	std::string j("564");
	std::string k("nihao");
	VEC_STRING vecArgs1;
	vecArgs1.push_back(j);
	vecArgs1.push_back(k);

	GMethodCreator::Invoke("test1", std::move(vecArgs));
	GMethodCreator::Invoke("A::test3", std::move(vecArgs1));

	std::array<std::string, 3> arrstr{"223", "dfre", "dsfer"};
	auto veci = array2tuple(arrstr);
	invoke(test3, veci);

	return 0;
}