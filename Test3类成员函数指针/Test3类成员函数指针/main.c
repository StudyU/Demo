#include <stdio.h>

int addc(int a, int b)
{
	return a+b;
}

void main()
{
	int(*p)(int, int) = addc;
	printf("%d\n", p(1,2));
	printf("%d\n", (*p)(1,2));//*p�������Զ���*p����Ϊp
	printf("%p, %p, %p\n",&p,*p,p);

	getchar();
}