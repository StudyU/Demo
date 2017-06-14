#include <algorithm> //辅助函数：较大值，较小值，交换
#include <iostream>
using namespace std;

bool int_ptr_less (int* a, int* b)
{
	return *a < *b;
}

int main()
{
	int x = 17;
	int y = 42;
	int* px = &x;
	int* py = &y;
	int* pmax;
	int* pmin;

	pmax = max(px, py, int_ptr_less);
	pmin = min(px, py, int_ptr_less);

	//swap(*pmax, *pmin);
	cout << "Max : " << *pmax << endl;
	cout << "Min : " << *pmin << endl;

}