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
void BubbleSort(int arr[], int size);//ð������
void QuickSort(int A[], int startingsub, int endingsub);//��������
void InsertionSort(int L[], const int begin, const int n);//��������
void Shellsort(int L[], const int left, const int right);//ϣ������
void CountingSort(int L[], const int n);//��������
int getDigit(int num, int dig);//���������л�ȡ��digλ������
void RadixSort(int L[], int left, int right, int d);//��������
void printArray(const int Array[], const int arraySize);//�������
int main()
{
	clock_t start, finish;
	double  duration;
	/* ����һ���¼�������ʱ��*/
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
		//��������
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		CountingSort(a, size);

		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "��������:", duration);
		*ofs << "��" << i << "��:\n " << "�������ݣ�0~999��" << size << " ������\n";
		*ofs << "��" << i << "�μ�������:\n " << "		Time:	" << fixed << duration << " seconds\n";
		//��������
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		RadixSort(a, 0, size - 1, 3);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "��������:", duration);
		*ofs << "��" << i << "�λ�������:\n " << "		Time:	" << duration << " seconds\n";
		//������
		MinHeap<int> mhp(a, size);
		start = clock();
		for (int k = 0; k <size; k++)
		{
			mhp.RemoveMin(a[k]);
		}
		finish = clock();
		//	printArray(a,size);
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "������:", duration);
		*ofs << "��" << i << "�ζ�����:\n " << "		Time:	" << duration << " seconds\n";
		//��������
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
		printf("%s%f seconds\n", "��������:", duration);
		*ofs << "��" << i << "�ο�������:\n " << "		Time:	" << duration << " seconds\n";
		//ϣ������
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		Shellsort(a, 0, size - 1);

		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "ϣ������:", duration);
		*ofs << "��" << i << "��ϣ������:\n " << "		Time:	" << duration << " seconds\n";

		//��������
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		InsertionSort(a, 0, size - 1);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "��������:", duration);
		*ofs << "��" << i << "�β�������:\n " << "		Time:	" << duration << " seconds\n";
		//ð������
		for (int k = 0; k <size; k++)
		{
			a[k] = b[k];
		}
		start = clock();
		BubbleSort(a, size);
		finish = clock();
		//	printArray(a,size);

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%s%f seconds\n", "ð������:", duration);
		*ofs << "��" << i << "��ð������:\n " << "		Time:	" << duration << " seconds\n";
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
