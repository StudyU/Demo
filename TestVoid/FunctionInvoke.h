#pragma once
#include <type_traits>
#include <array>

template<typename Function, typename Tuple, std::size_t... Index>
decltype(auto) invoke_impl(Function&& func, Tuple&& t, std::index_sequence<Index...>)
{
	return func(std::get<Index>(std::forward<Tuple>(t))...);
}

template<typename Function, typename Tuple>
decltype(auto) invoke(Function&& func, Tuple&& t)
{
	constexpr auto size = std::tuple_size<typename std::decay<Tuple>::type>::value;
	return invoke_impl(std::forward<Function>(func), std::forward<Tuple>(t), std::make_index_sequence<size>{});
}

template<typename Array, std::size_t... Index>
decltype(auto) array2tuple_impl(const Array& a, std::index_sequence<Index...>)
{
	return std::make_tuple(a[Index]...);
}

template<typename T, std::size_t N>
decltype(auto) array2tuple(const std::array<T, N>& a)
{
	return array2tuple_impl(a, std::make_index_sequence<N>{});
}