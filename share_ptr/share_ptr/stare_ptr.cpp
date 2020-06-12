#include <iostream>  
#include <memory>  
#include <windows.h>
#include "share_ptr.h"

typedef void(*deleter)(A*); //define a function type pointer to free;  
int main()
{
	std::shared_ptr<A> spa(A::alloc(), &A::free);//deleter: &A::free()  

	deleter* del = std::get_deleter<deleter>(spa);
	std::cout << "get_deleter(spa)!=0 == " << std::boolalpha << (del != 0) << std::endl;

	system("pause");
	return 0;
}