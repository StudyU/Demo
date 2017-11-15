#include <Windows.h>
#include <iostream>  
#include <algorithm>  
using namespace std;
/*
堆排序的时间复杂度为O(nlogn)；空间复杂度为O(1)；是不稳定的排序算法
*/

// 最大堆
void max_heapify(int arr[], int start, int end) 
{
	//建立父節點指標和子節點指標  
	int dad = start;
	int son = dad * 2 + 1;
	while (son < end)	//若子節點指標在範圍內才做比較  
	{ 
		if (son + 1 < end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的  
			son++;
		if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數  
			return;
		else //否則交換父子內容再繼續子節點和孫節點比較
		{   
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) 
{
	//初始化，i從最後一個父節點開始調整  
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len);
	//先將第一個元素和已排好元素前一位做交換，再從新調整，直到排序完畢  
	for (int i = len - 1; i > 0; i--) 
	{
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i);
	}
}

int main() 
{
	int arr[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}
/*
int n;  ///数字个数，n很大(n>10000)
int dui[10];
#define K 10    ///Top K,K的取值

//从上到下调整
void UpToDown(int i)
{
	int t1, t2, tmp, pos;
	t1 = 2 * i; ///左孩子(存在的话)
	t2 = t1 + 1;    ///右孩子(存在的话)
	if (t1>K)    ///无孩子节点
		return;
	else
	{
		if (t2>K)  ///只有左孩子
			pos = t1;
		else
			pos = dui[t1]>dui[t2] ? t2 : t1;

		if (dui[i]>dui[pos]) ///pos保存在子孩子中，数值较小者的位置
		{
			tmp = dui[i]; dui[i] = dui[pos]; dui[pos] = tmp;
			UpToDown(pos);
		}
	}
}

//建堆
void create_dui()
{
	int i;
	int pos = K / 2;      ///从末尾数，第一个非叶节点的位置K/2
	for (i = pos; i >= 1; i--)
		UpToDown(i);
}

int main()
{
	int i;
	int tmp;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= K; i++) ///先输入K个
			scanf_s("%d", &dui[i]);
		create_dui();  ///建小顶堆
		for (i = K + 1; i <= n; i++)
		{
			scanf_s("%d", &tmp);
			if (tmp>dui[1])  ///只有大于根节点才处理
			{
				dui[1] = tmp;
				UpToDown(1);    ///向下调整堆
			}
		}
	}

	return 1;
}
*/
