#include <vector>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;
using std::ofstream;
using std::vector;

//http://blog.csdn.net/mfcing/article/details/8746256
/*
�ڴ������ƣ����ռ䲻��ʱ��������50%���Բ���������Ϊ��ǰ���������������ݸ���
����vector���򵥵ؽ�����һ����̬���飬������һ��ָ��ָ��һƬ�������ڴ�ռ䣬���ռ䲻��װ������ʱ���Զ�������һƬ����Ŀռ䣬
Ȼ���ԭ�����ݿ�����ȥ�������ͷ�ԭ������Ƭ�ռ䣻���ͷŻ���˵��ɾ�����������ʱ����洢�ռ䲢�����ͷţ�����ֻ����������������.
capacity()���ص��ǵ�ǰvector���󻺳���������Ķ�vectorά�����ڴ�ռ�Գ�Ϊ��������ʵ������Ŀռ��С��
��size()���ص��ǵ�ǰ���󻺳����д洢���ݵĸ�����capacity��Զ�Ǵ��ڵ���size�ģ�
��size��capacity���ʱ�����������ʱvector������
reserveֻ�Ǳ���һ����С�Ŀռ��С����resize���ǶԻ������������·��䣬�����漰�����жϺ��ڴ洦��Ƚ϶�
*/
int main()
{
	/*
	vector<int> arr1;
	ofstream wf("1.txt");
	clock_t start = clock();	// ��ʱ��λms(��׼C/C++�У���С�ļ�ʱ��λ��1����)
	for (int i = 0; i < 100; ++i)
	{
		arr1.push_back(i);
		wf << "capacity=" << arr1.capacity() << ",size=" << arr1.size() << endl;
	}
	wf << clock() - start << endl;
	wf.close();
	*/

	/************************************************************************/
	/* vector���ǿ���ͷ��ڴ�ռ�											*/
	/* Ĭ��ֻ������ʱ�Ż��ͷ�												*/
	/************************************************************************/

	vector<int> arr;
	cout << "Ĭ�����δ��ʼ��ʱ��capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.resize(100, 100);
	cout << "����1��capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.reserve(50);
	cout << "����2��capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.resize(50);
	cout << "����3��capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	vector<int>::iterator itor = arr.begin() + 10;
	arr.erase(arr.begin(), itor);
	cout << "���capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	
	//����һ��
	vector<int>().swap(arr); //ǿ���ͷſռ�
	/*
	//��������
	{
		vector<int> temp;//��ʱ����δ��ʼ�����仺������СΪ0��û������
		arr.swap(temp);	//�����ǵĶ��󽻻����ݣ�arr�Ļ�������û�ˡ�  					 
	}//��ʱ�����ᱻ������temp����vector���������ͷſռ�
	*/
	cout << "�ͷţ�capacity=" << arr.capacity() << ",size=" << arr.size() << endl;

	/*
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
	*/
	system("pause");
	return 0;
}

/*
reserve������Ԥ���ռ䣬��������������Ԫ�ض����ڴ�������֮ǰ���������������ڵ�Ԫ�أ���˵������µ�Ԫ��ʱ����Ҫ��push_back()/insert()������
resize�Ǹı������Ĵ�С�����Ҵ���������ˣ������������֮�󣬾Ϳ������������ڵĶ����ˣ���˵������µ�Ԫ��ʱ����operator[]�������������õ�����������Ԫ�ض���
*/