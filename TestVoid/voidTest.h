#include <functional>
#include <tuple>
#include <map>
#include <memory>
//
//template<typename RType, typename ...Args>
//class GMEvent
//{
//public:
//	typedef std::function<RType(Args...)> GM_EVENT_FUNCTOR;
//	typedef std::shared_ptr<GM_EVENT_FUNCTOR> GM_EVENT_FUNCTOR_PTR;
//
//	static void GMAdd(std::string funcName, GM_EVENT_FUNCTOR func)
//	{
//		GM_EVENT_FUNCTOR_PTR functorPtr(new GM_EVENT_FUNCTOR(func));
//		m_func.insert(std::make_pair(funcName, functorPtr));
//	}
//
//	typedef std::map<std::string, GM_EVENT_FUNCTOR_PTR> GMMAP;
//
//	static GMMAP m_func;
//};

template<typename T>
struct function_traits;

template<typename R, typename ...Args>
struct function_traits<std::function<R(Args...)>>
{
	typedef R result_type;
	//const size_t nargs = sizeof...(Args);

	template <size_t i>
	struct arg
	{
		typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
	};
};


