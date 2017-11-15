#include <Windows.h>
#include <iostream>  
#include <algorithm>  
using namespace std;
/*
�������ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(1)���ǲ��ȶ��������㷨
*/

// ����
void max_heapify(int arr[], int start, int end) 
{
	//���������cָ�˺��ӹ��cָ��  
	int dad = start;
	int son = dad * 2 + 1;
	while (son < end)	//���ӹ��cָ���ڹ����Ȳ������^  
	{ 
		if (son + 1 < end && arr[son] < arr[son + 1]) //�ȱ��^�ɂ��ӹ��c��С���x������  
			son++;
		if (arr[dad] > arr[son]) //��������c����ӹ��c�����{���ꮅ��ֱ����������  
			return;
		else //��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
		{   
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) 
{
	//��ʼ����i������һ�������c�_ʼ�{��  
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len);
	//�Ȍ���һ��Ԫ�غ����ź�Ԫ��ǰһλ�����Q���ُ����{����ֱ�������ꮅ  
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
int n;  ///���ָ�����n�ܴ�(n>10000)
int dui[10];
#define K 10    ///Top K,K��ȡֵ

//���ϵ��µ���
void UpToDown(int i)
{
	int t1, t2, tmp, pos;
	t1 = 2 * i; ///����(���ڵĻ�)
	t2 = t1 + 1;    ///�Һ���(���ڵĻ�)
	if (t1>K)    ///�޺��ӽڵ�
		return;
	else
	{
		if (t2>K)  ///ֻ������
			pos = t1;
		else
			pos = dui[t1]>dui[t2] ? t2 : t1;

		if (dui[i]>dui[pos]) ///pos�������Ӻ����У���ֵ��С�ߵ�λ��
		{
			tmp = dui[i]; dui[i] = dui[pos]; dui[pos] = tmp;
			UpToDown(pos);
		}
	}
}

//����
void create_dui()
{
	int i;
	int pos = K / 2;      ///��ĩβ������һ����Ҷ�ڵ��λ��K/2
	for (i = pos; i >= 1; i--)
		UpToDown(i);
}

int main()
{
	int i;
	int tmp;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= K; i++) ///������K��
			scanf_s("%d", &dui[i]);
		create_dui();  ///��С����
		for (i = K + 1; i <= n; i++)
		{
			scanf_s("%d", &tmp);
			if (tmp>dui[1])  ///ֻ�д��ڸ��ڵ�Ŵ���
			{
				dui[1] = tmp;
				UpToDown(1);    ///���µ�����
			}
		}
	}

	return 1;
}
*/
