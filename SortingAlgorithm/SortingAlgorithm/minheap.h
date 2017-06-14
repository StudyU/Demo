#pragma once
//使用时注意将关键码加入
#ifndef MINHEAP_H
#define MINHEAP_H
#include <assert.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
#include <stdlib.h>
//const int maxPQSize = 50;  
template <class Type> class MinHeap {
public:
	MinHeap(int maxSize);//根据最大长度建堆
	MinHeap(Type arr[], int n);//根据数组arr[]建堆
	~MinHeap() { delete[] heap; }
	const MinHeap<Type> & operator = (const MinHeap &R);//重载赋值运算符
	int Insert(const Type &x);//插入元素
	int RemoveMin(Type &x);//移除关键码最小的元素，并赋给x
	int IsEmpty() const { return CurrentSize == 0; }//检查堆是否为空     
	int IsFull() const { return CurrentSize == MaxHeapSize; }//检查对是否满
	void MakeEmpty() { CurrentSize = 0; }//使堆空
private:
	enum { DefaultSize = 50 };//默认堆的大小
	Type *heap;
	int CurrentSize;
	int MaxHeapSize;
	void FilterDown(int i, int m);//自上向下调整堆
	void FilterUp(int i);//自下向上调整堆
};
template <class Type> MinHeap <Type>::MinHeap(int maxSize)
{
	//根据给定大小maxSize,建立堆对象
	MaxHeapSize = (DefaultSize < maxSize) ? maxSize : DefaultSize;	        //确定堆大小
	heap = new Type[MaxHeapSize];  //创建堆空间
	CurrentSize = 0;                               //初始化
}
template <class Type> MinHeap <Type>::MinHeap(Type arr[], int n)
{
	//根据给定数组中的数据和大小,建立堆对象    
	MaxHeapSize = DefaultSize < n ? n : DefaultSize;
	heap = new Type[MaxHeapSize];
	if (heap == NULL) { cerr << "fail" << endl; exit(1); }
	for (int i = 0; i< n; i++)
		heap[i] = arr[i];               //数组传送
	CurrentSize = n;       //当前堆大小
	int currentPos = (CurrentSize - 2) / 2;   //最后非叶
	while (currentPos >= 0) {
		//从下到上逐步扩大,形成堆
		FilterDown(currentPos, CurrentSize - 1);
		currentPos--;
		//从currentPos开始,到0为止, 调整currentPos--; }
	}
}
template <class Type> void MinHeap<Type>::FilterDown(const int start, const int EndOfHeap)
{
	// 结点i的左、右子树均为堆，调整结点i
	int i = start, j = 2 * i + 1;           // j 是 i 的左子女
	Type temp = heap[i];
	while (j <= EndOfHeap) {
		if (j < EndOfHeap && heap[j] > heap[j + 1])
			j++;//两子女中选小者
		if (temp <= heap[j]) break;
		else { heap[i] = heap[j];  i = j;   j = 2 * j + 1; }
	}
	heap[i] = temp;
}
template <class Type> int MinHeap<Type>::Insert(const Type &x)
{
	//在堆中插入新元素 x
	if (CurrentSize == MaxHeapSize)       //堆满
	{
		cout << "堆已满" << endl;  return 0;
	}
	heap[CurrentSize] = x;           //插在表尾  
	FilterUp(CurrentSize);          //向上调整为堆
	CurrentSize++;                       //堆元素增一
	return 1;
}
template <class Type> void MinHeap<Type>::FilterUp(int start)
{
	//从 start 开始,向上直到0,调整堆
	int j = start, i = (j - 1) / 2;    // i 是 j 的双亲
	Type temp = heap[j];
	while (j > 0) {
		if ((heap[i].root->data.key) <= (temp.root->data.key)) break;
		else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }
	}
	heap[j] = temp;
}
template <class Type> int MinHeap <Type>::RemoveMin(Type &x)
{
	if (!CurrentSize)
	{
		cout << "堆已空 " << endl;
		return 0;
	}
	x = heap[0];             //最小元素出队列
	heap[0] = heap[CurrentSize - 1];
	CurrentSize--;        //用最小元素填补
	FilterDown(0, CurrentSize - 1);
	//从0号位置开始自顶向下调整为堆
	return 1;
}
#endif
