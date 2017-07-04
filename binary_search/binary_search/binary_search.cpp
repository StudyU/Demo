#include <iostream>
#include <windows.h>
using namespace std;

// 二分法查找,数组必须是有序的
//int binary_search(int arry[], int n, int value)
//指针传递效率更高
int binary_search(int* arry, int n, int value)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		// 防止溢出，移位也更高效
		int middle = left + ((right - left) >> 1);

		if (value > *(arry+middle))
		{
			left = middle + 1;
		}
		else if (value < *(arry+middle))
		{
			right = middle - 1;
		}
		else
			return middle;
	}

	return -1;
}

int main()
{
	int a[10] = {0,1,3,4,6,7,9,13,15,19};
	int putin;
	cout << "Please enter you want to find number: ";
	cin >> putin;
	int loc = binary_search(a, 10, putin);

	if (loc == -1)
	{
		cout << "Not find at a[10]!" << endl;
	}
	else
	{
		cout << "find " << putin << " at a[" << loc << "]" << endl;
	}

	system("pause");
	return 0;
}