#include "Complex.h"

int main()
{
	Complex Com1;
	Complex Com2;
	Complex Com3;

	Com1.Reset(10.2, 10.2);
	Com1.Put("Com1");

	Com2.Reset(-1.2, -2.2);
	Com2.Put("Com2");

	Com3 = Com1;
	Com3.Put("3=1");

	Com3 = Com1 + Com2;
	Com3.Put("3=1+2");


	return 0;
}