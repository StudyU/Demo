#include <iostream>  
#include <memory>  
#include <windows.h>
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
typedef void(*deleter)(A*); //define a function type pointer to free;  
int main()
{
	std::shared_ptr<A> spa(A::alloc(), &A::free);//deleter: &A::free()  

	deleter* del = std::get_deleter<deleter>(spa);
	std::cout << "get_deleter(spa)!=0 == " << std::boolalpha << (del != 0) << std::endl;

	system("pause");
	return 0;
}