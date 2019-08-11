#include <vector>
#include <iostream>
#include "voidTest.h"
#include <string>

// https://en.cppreference.com/w/cpp/utility/functional/invoke
// https://www.jianshu.com/p/b90d1091a4ff
//class GetArgsVal https://stackoverflow.com/questions/9065081/how-do-i-get-the-argument-types-of-a-function-pointer-in-a-variadic-template-cla#
//{
//public:
//	GetArgsVal(const std::vector<void*>& vec) :m_vecArgs(vec), m_index(m_vecArgs.size())
//	{}
//
//	template<typename T>
//	T GetVal()
//	{
//		return *(T*)m_vecArgs[--m_index];
//	}
//private:
//	const std::vector<void*>& m_vecArgs;
//	int m_index;
//};
//
//template<typename ReType, typename...ArgsType>
//ReType GmArgsCall(const std::vector<void*>& args, ReType(*func)(ArgsType...))
//{
//	GetArgsVal ArgsGet(args);
//	return func(ArgsGet.GetVal<ArgsType>()...);
//}
//

template<typename Func, typename T, size_t... I>
void invoke_impl(Func f, T t, std::index_sequence<I...>)
{
	f(std::get<I>(t)...);
}

template<typename Func, typename... T >
void invoke(Func f, T... t)
{
	invoke_impl(f, std::make_tuple(t...), std::make_index_sequence<sizeof...(T)>());
	//std::invoke(f, t...);
}

//template<typename Class, typename Func, typename... T >
//void invoke(Class* obj, Func f, T... t)
//{
//	//invoke_impl(f, std::make_tuple(t...), std::make_index_sequence<sizeof...(T)>());
//	std::invoke(f, obj, t...);
//}

template<typename Function, typename Tuple, std::size_t... Index>
decltype(auto) invoke_impl1(Function&& func, Tuple&& t, std::index_sequence<Index...>)
{
	return func(std::get<Index>(std::forward<Tuple>(t))...);
}

template<typename Function, typename Tuple>
decltype(auto) invoke1(Function&& func, Tuple&& t)
{
	constexpr auto size = std::tuple_size<typename std::decay<Tuple>::type>::value;
	return invoke_impl1(std::forward<Function>(func), std::forward<Tuple>(t), std::make_index_sequence<size>{});
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
		std::cout << "static A::test2"<< x << std::endl;
	}

	int test3(int i, std::string y)
	{
		std::cout << i <<  y << std::endl;
		return 0;
	}
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

double test3(int j, std::string str, double f)
{
	std::cout << j << std::endl; 
	std::cout << str << std::endl;
	std::cout << f << std::endl;
	return 0.0;
}

std::string test4(std::string& k)
{
	std::cout << k << std::endl;
	return k;
}

template<typename RType, typename ...Args>
GMEvent<RType, Args... >::GMMAP GMEvent::m_func;

int main()
{
	int i = 9;
	std::string str("nihao");
	double f = 0.0;
	std::string str1("C++");
	std::string strI("9");
	std::string strD("0.0");

	auto args = std::make_tuple(i, str, f);
	auto argstr = std::make_tuple(strI, str, strD);
	
	std::vector<void*> vec;
	vec.push_back(&i);
	vec.push_back(&str);
	vec.push_back(&f);
	vec.push_back(&str1);

	int t1 = *(int*)vec[0];
	std::string t2 = *(std::string*)vec[1];
	double t3 = *(double*)vec[2];
	
	//GmArgsCall(vec, test1);
	//GmArgsCall(vec, test2);
	//GmArgsCall(vec, test3);
	//GmArgsCall(vec, test4);
	//invoke(test4, i, str);
	//std::invoke(test1, i);
	//std::invoke(test2);
	//std::invoke(test3, i, str, f);
	//std::invoke(test4, str1);
	//invoke(test4,std::move(str));
	//invoke(test3, std::move(str1));
	//invoke1(test3, args);
	invoke(test2);
	//invoke(test3, i, str, f);
	//A a;
	//invoke(&(A::test), a, 3);
	//invoke(A::test2, 3.9);
	//invoke(&(A::test3), a, std::make_tuple(9, "dsd"));

	//std::cout << function_traits<test1>::arg<0>::size_type << std::endl;

	//GMEvent<int, int>::GMAdd(str1, test1);
	GMEvent<int, int>::GMAdd(str, test1);

	return 0;
}

void fu()
{

	return;
}