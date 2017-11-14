#include <vector>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;
using std::ofstream;
using std::vector;

int main()
{
	/************************************************************************/
	/* vector���ǿ���ͷ��ڴ�ռ�											*/
	/* Ĭ��ֻ������ʱ�Ż��ͷ�												*/
	/************************************************************************/
	vector<int> arr;
	cout << "Ĭ�����δ��ʼ��ʱ��capacity=" << arr.capacity() << endl;
	arr.resize(100, 100);
	arr.reserve(50);
	arr.resize(50);
	cout << "���ڣ�capacity=" << arr.capacity() << endl;
	vector<int>::iterator itor = arr.begin() + 10;
	arr.erase(arr.begin(), itor);
	cout << "capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	// 	//����һ��
	vector<int>().swap(arr); //ǿ���ͷſռ�
							 //��������
	{
		vector<int> temp;
		arr.swap(temp);
	}//��ʱ�����ᱻ����
	cout << "capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	clock_t start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v1;
		for (int i = 0; i<100; ++i)
			v1.push_back(i);
	}
	cout << "ֱ��pushѭ��10000����ʱ��" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v2;
		v2.resize(100);
		for (int i = 0; i<100; ++i)
			v2[i] = i;
	}
	cout << "��resizeԤ���С��pushѭ��10000����ʱ��" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v3;
		v3.reserve(100);
		for (int i = 0; i<100; ++i)
			v3.push_back(i);
	}
	cout << "��reserveԤ���С��pushѭ��10000����ʱ��" << clock() - start << endl;
	vector<int> v4;
	ofstream wf("2.txt");
	int nFlag = v4.capacity();
	for (int i = 0; i<100; ++i)
	{
		v4.push_back(i);
		if (nFlag != v4.capacity())
		{
			nFlag = v4.capacity();
			cout << "new buffer size=" << nFlag << endl;
			wf << "capacity=" << nFlag << endl;
		}
	}
	wf.close();
	cout << "max_size=" << arr.max_size() << endl;
	return 0;
}