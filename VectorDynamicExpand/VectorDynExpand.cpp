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
内存分配机制：当空间不足时，先扩容50%，仍不够是容量为当前容量加上新增数据个数
关于vector，简单地讲就是一个动态数组，里面有一个指针指向一片连续的内存空间，当空间不够装下数据时会自动申请另一片更大的空间，
然后把原有数据拷贝过去，接着释放原来的那片空间；当释放或者说是删除里面的数据时，其存储空间并不会释放，仅仅只是清空了里面的数据.
capacity()返回的是当前vector对象缓冲区（后面的对vector维护的内存空间皆称为缓冲区）实际申请的空间大小，
而size()返回的是当前对象缓冲区中存储数据的个数，capacity永远是大于等于size的，
当size和capacity相等时继续添加数据时vector会扩容
reserve只是保持一个最小的空间大小，而resize则是对缓冲区进行重新分配，里面涉及到的判断和内存处理比较多
*/
int main()
{
	/*
	vector<int> arr1;
	ofstream wf("1.txt");
	clock_t start = clock();	// 计时单位ms(标准C/C++中，最小的计时单位是1毫秒)
	for (int i = 0; i < 100; ++i)
	{
		arr1.push_back(i);
		wf << "capacity=" << arr1.capacity() << ",size=" << arr1.size() << endl;
	}
	wf << clock() - start << endl;
	wf.close();
	*/

	/************************************************************************/
	/* vector如何强制释放内存空间											*/
	/* 默认只有析构时才会释放												*/
	/************************************************************************/

	vector<int> arr;
	cout << "默认情况未初始化时，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.resize(100, 100);
	cout << "现在1，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.reserve(50);
	cout << "现在2，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	arr.resize(50);
	cout << "现在3，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	vector<int>::iterator itor = arr.begin() + 10;
	arr.erase(arr.begin(), itor);
	cout << "最后，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	
	//方法一、
	vector<int>().swap(arr); //强制释放空间
	/*
	//方法二、
	{
		vector<int> temp;//临时对象未初始化，其缓冲区大小为0，没有数据
		arr.swap(temp);	//与我们的对象交换数据，arr的缓冲区就没了。  					 
	}//临时变量会被析构，temp调用vector析构函数释放空间
	*/
	cout << "释放，capacity=" << arr.capacity() << ",size=" << arr.size() << endl;

	/*
	clock_t start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v1;
		for (int i = 0; i<100; ++i)
			v1.push_back(i);
	}
	cout << "直接push循环10000次用时：" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v2;
		v2.resize(100);
		for (int i = 0; i<100; ++i)
			v2[i] = i;
	}
	cout << "先resize预设大小再push循环10000次用时：" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v3;
		v3.reserve(100);
		for (int i = 0; i<100; ++i)
			v3.push_back(i);
	}
	cout << "先reserve预设大小再push循环10000次用时：" << clock() - start << endl;
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
reserve是容器预留空间，但并不真正创建元素对象，在创建对象之前，不能引用容器内的元素，因此当加入新的元素时，需要用push_back()/insert()函数。
resize是改变容器的大小，并且创建对象，因此，调用这个函数之后，就可以引用容器内的对象了，因此当加入新的元素时，用operator[]操作符，或者用迭代器来引用元素对象
*/