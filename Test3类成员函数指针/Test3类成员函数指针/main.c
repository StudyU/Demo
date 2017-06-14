#include <stdio.h>

int addc(int a, int b)
{
	return a+b;
}

void main()
{
	int(*p)(int, int) = addc;
	printf("%d\n", p(1,2));
	printf("%d\n", (*p)(1,2));//*p编译器自动将*p解释为p
	printf("%p, %p, %p\n",&p,*p,p);

	getchar();
}