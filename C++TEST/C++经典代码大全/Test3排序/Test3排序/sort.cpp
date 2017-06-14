#include <iostream>
#include <string>
using namespace std;
//对数组进行排序
template <class T>
void arr_out(T arr[], const int size)
{
	for (int i=0; i<size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//选择排序法
template <class T>
void sort(T arr[], const int size)
{
	for (int i=0; i<size; ++i)
	{
		for (int j=i+1; j<size;++j)
		{
			if (arr[i]>arr[j])
			{
				T temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//二分查找法(必须是已经排序好的数组中)
template <class T>
int binary_search(T arr[], const int val, const int size)
{
	int found = 0;
	int high = size;
	int low = 0;
	int mid = (high+low)/2;

	while ((!found)&&(high>=low))
	{
		if (val == arr[mid])
		{
			found = 1;
		}
		else if(val < arr[mid])
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
		mid = (high+low)/2;
	}
	return (found)?mid:-1;
}

//快速排序法
/*
template <class T>
void SequenceList<T>::Quick_Sort(int count, int low, int high)
{
	int i, j;
	T temp;

	if (low>=0&&low<count&&high>=0&&high<count&&high>low)
	{
		i = low;
		j = high;
		temp = Element[i];
		while (i!=j)
		{
			while (i<j&&temp<=Element[j])
			{
				j--;
			}
			if (i<j)
			{
				Element[i] = Element[j];
				i++;
			}
			while (i<j&&Element[i]<temp)
			{
				i++;
			}
			if (i<j)
			{
				Element[j] = Element[i];
				j--;
			}
		}
	}
	Element[i] = temp;
	Quick_Sort(count, low, j-1);
	Quick_Sort(count, i+1, high);
}
*/
int main()
{
	int arry[] = {1,3,23,7,22,34,2,55,55,10};
	int n = sizeof(arry)/sizeof(int);
	arr_out(arry, n);
	
	sort(arry, n);
	arr_out(arry, n);
	
	int findvalue;
	cout << "finding value: ";
	cin >> findvalue;
	cout << "num find: "
		<<binary_search(arry, findvalue, 10)<< endl;

	char ch1, str[] = "happy!";
	int size = strlen(str);
	arr_out(str, size);
	sort(str, size);
	arr_out(str, size);
	cout << "Enter You want find char:";
	cin >> ch1;
	cout << "char find: "
		<<binary_search(str, ch1, size) << endl;

	return 0;
}