#pragma once
//ʹ��ʱע�⽫�ؼ������
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
	MinHeap(int maxSize);//������󳤶Ƚ���
	MinHeap(Type arr[], int n);//��������arr[]����
	~MinHeap() { delete[] heap; }
	const MinHeap<Type> & operator = (const MinHeap &R);//���ظ�ֵ�����
	int Insert(const Type &x);//����Ԫ��
	int RemoveMin(Type &x);//�Ƴ��ؼ�����С��Ԫ�أ�������x
	int IsEmpty() const { return CurrentSize == 0; }//�����Ƿ�Ϊ��     
	int IsFull() const { return CurrentSize == MaxHeapSize; }//�����Ƿ���
	void MakeEmpty() { CurrentSize = 0; }//ʹ�ѿ�
private:
	enum { DefaultSize = 50 };//Ĭ�϶ѵĴ�С
	Type *heap;
	int CurrentSize;
	int MaxHeapSize;
	void FilterDown(int i, int m);//�������µ�����
	void FilterUp(int i);//�������ϵ�����
};
template <class Type> MinHeap <Type>::MinHeap(int maxSize)
{
	//���ݸ�����СmaxSize,�����Ѷ���
	MaxHeapSize = (DefaultSize < maxSize) ? maxSize : DefaultSize;	        //ȷ���Ѵ�С
	heap = new Type[MaxHeapSize];  //�����ѿռ�
	CurrentSize = 0;                               //��ʼ��
}
template <class Type> MinHeap <Type>::MinHeap(Type arr[], int n)
{
	//���ݸ��������е����ݺʹ�С,�����Ѷ���    
	MaxHeapSize = DefaultSize < n ? n : DefaultSize;
	heap = new Type[MaxHeapSize];
	if (heap == NULL) { cerr << "fail" << endl; exit(1); }
	for (int i = 0; i< n; i++)
		heap[i] = arr[i];               //���鴫��
	CurrentSize = n;       //��ǰ�Ѵ�С
	int currentPos = (CurrentSize - 2) / 2;   //����Ҷ
	while (currentPos >= 0) {
		//���µ���������,�γɶ�
		FilterDown(currentPos, CurrentSize - 1);
		currentPos--;
		//��currentPos��ʼ,��0Ϊֹ, ����currentPos--; }
	}
}
template <class Type> void MinHeap<Type>::FilterDown(const int start, const int EndOfHeap)
{
	// ���i������������Ϊ�ѣ��������i
	int i = start, j = 2 * i + 1;           // j �� i ������Ů
	Type temp = heap[i];
	while (j <= EndOfHeap) {
		if (j < EndOfHeap && heap[j] > heap[j + 1])
			j++;//����Ů��ѡС��
		if (temp <= heap[j]) break;
		else { heap[i] = heap[j];  i = j;   j = 2 * j + 1; }
	}
	heap[i] = temp;
}
template <class Type> int MinHeap<Type>::Insert(const Type &x)
{
	//�ڶ��в�����Ԫ�� x
	if (CurrentSize == MaxHeapSize)       //����
	{
		cout << "������" << endl;  return 0;
	}
	heap[CurrentSize] = x;           //���ڱ�β  
	FilterUp(CurrentSize);          //���ϵ���Ϊ��
	CurrentSize++;                       //��Ԫ����һ
	return 1;
}
template <class Type> void MinHeap<Type>::FilterUp(int start)
{
	//�� start ��ʼ,����ֱ��0,������
	int j = start, i = (j - 1) / 2;    // i �� j ��˫��
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
		cout << "���ѿ� " << endl;
		return 0;
	}
	x = heap[0];             //��СԪ�س�����
	heap[0] = heap[CurrentSize - 1];
	CurrentSize--;        //����СԪ���
	FilterDown(0, CurrentSize - 1);
	//��0��λ�ÿ�ʼ�Զ����µ���Ϊ��
	return 1;
}
#endif
