#include <stdio.h>
#include "..\Math\Math.h"

//__declspec(dllimport) double Sub(double a, double b);

int main(int argc, char **argv)
{
	double result = Add(1, 2);
	printf("result = %f", result);
	return 0;
}