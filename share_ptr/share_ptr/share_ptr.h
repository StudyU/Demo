#ifndef _SHARE_PTR_H_
#define _SHARE_PTR_H_
#include <iostream>
class A
{
public:
	static A* alloc()
	{
		A* pa = new A;
		std::cout << "a new object was created" << std::endl;
		return pa;
	}
	static void free(A* pa)
	{
		delete pa;
		std::cout << "A object was destroyed" << std::endl;
	}
};

#endif // ! _SHARE_PTR_H_
