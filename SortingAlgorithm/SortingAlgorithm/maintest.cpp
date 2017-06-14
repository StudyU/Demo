#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cstdlib>
#include <ctime>
#include<iostream>
using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
#include<iomanip>
using std::setw;
using std::fixed;
#include<fstream>
using std::ifstream;
using std::ofstream;
using std::flush;
#include<string>
using std::string;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"minheap.h"
void BubbleSort(int arr[], int size);//冒泡排序
void QuickSort(int A[], int startingsub, int endingsub);//快速排序
void InsertionSort(int L[], const int begin, const int n);//插入排序
void Shellsort(int L[], const int left, const int right);//希尔排序
void CountingSort(int L[], const int n);//计数排序
int getDigit(int num, int dig);//基数排序中获取第dig位的数字
void RadixSort(int L[], int left, int right, int d);//基数排序
void printArray(const int Array[], const int arraySize);//输出数组
int main()
{
	clock_t start, finish;
	double  duration;
	/* 测量一个事件持续的时间*/
	ofstream *ofs;
	string fileName = "sortResult.txt";
	ofs = new ofstream(fileName.c_str(), ios::out | ios::app);
	const int size = 100000;
	int a[size];
	int b[size];
	srand(time(NULL));
	ofs->close();
	for (int i = 0; i < 20; i++)
	{
		ofs->open(fileName.c_str(), ios::out | ios::app);
		if (ofs->fail()) {
			cout << "!!";
			ofs->close();
		}
		for (int k = 0; k <size; k++)
		{
			a[k] = rand() % 1000;
			b[k] = a[k];

		}
		/*	for( k =0; k <size;k++)
		{
		a[k] = k;
		b[k] = a[k];

		} */
		//printArray(a,size);	
		//计数排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		CountingSort(a, size);

		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "计数排序:", duration);
		*ofs << "第" << i << "次:\n " << "排序内容：0~999共" << size << " 个整数\n";
		*ofs << "第" << i << "次计数排序:\n " << "		Time:	" << fixed << duration << " seconds\n";
		//基数排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		RadixSort(a, 0, size - 1, 3);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "基数排序:", duration);
		*ofs << "第" << i << "次基数排序:\n " << "		Time:	" << duration << " seconds\n";
		//堆排序
		MinHeap<int> mhp(a, size);
		start = clock();
		for (int k = 0; k <size; k++)
		{
			mhp.RemoveMin(a[k]);
		}
		finish = clock();
		//	printArray(a,size);
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "堆排序:", duration);
		*ofs << "第" << i << "次堆排序:\n " << "		Time:	" << duration << " seconds\n";
		//快速排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];

		}
		//printArray(a,size);
		start = clock();
		QuickSort(a, 0, size - 1);
		finish = clock();
		//	printArray(a,size);
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "快速排序:", duration);
		*ofs << "第" << i << "次快速排序:\n " << "		Time:	" << duration << " seconds\n";
		//希尔排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		Shellsort(a, 0, size - 1);

		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "希尔排序:", duration);
		*ofs << "第" << i << "次希尔排序:\n " << "		Time:	" << duration << " seconds\n";

		//插入排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		InsertionSort(a, 0, size - 1);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "插入排序:", duration);
		*ofs << "第" << i << "次插入排序:\n " << "		Time:	" << duration << " seconds\n";
		//冒泡排序
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		BubbleSort(a, size);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "冒泡排序:", duration);
		*ofs << "第" << i << "次冒泡排序:\n " << "		Time:	" << duration << " seconds\n";
		ofs->close();
	}
	return 0;
}
void printArray(const int Array[], const int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		cout << Array[i] << "   ";
		if (i % 20 == 19)
			cout << endl;
	}
	cout << endl;
}
