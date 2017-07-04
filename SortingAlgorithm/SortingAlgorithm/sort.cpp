/*
稳定的排序算法：

冒泡排序（bubble sort） — O(n2)

鸡尾酒排序(Cocktail sort, 双向的冒泡排序) — O(n2)

插入排序 （insertion sort）— O(n2)

桶排序 （bucket sort）— O(n); 需要 O(k) 额外 记忆体

归并排序 （merge sort）— O(n log n); 需要 O(n) 额外记忆体

原地归并排序 — O(n2)

二叉树排序 （Binary tree sort） — O(n log n); 需要 O(n) 额外记忆体

基数排序 （radix sort）— O(n·k); 需要 O(n) 额外记忆体


不稳定的排序算法：

选择排序 （selection sort）— O(n2)

希尔排序 （shell sort）— O(n log n) 如果使用最佳的现在版本

Comb sort — O(n log n)

堆排序 （heapsort）— O(n log n)

Smoothsort — O(n log n)

快速排序 （quicksort）— O(n log n) 期望时间, O(n2) 最坏情况; 对於大的、乱数串列一般相信是最快的已知排序

一般来说：存在不相邻交换的排序算法是不稳定的，相邻交换的排序算法是稳定的；对于相邻交换的稳定排序算法，通过控制交换条件可以转换成不稳定排序算法；冒泡、插入、归并和基数排序是稳定的；选择、快速、希尔和堆排序是不稳定的。
*/

//n^2
//冒泡排序V[n]不参与排序
void BubbleSort(int V[], int n)
{
	bool exchange;	     //设置交换标志置
	for (int i = 0; i < n; i++) {
		exchange = false;
		for (int j = n - 1; j>i; j--) { //反向检测，检查是否逆序
			if (V[j - 1] > V[j]) //发生逆序，交换相邻元素
			{
				int temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
				exchange = true;//交换标志置位
			}
		}

		if (exchange == false)
			return; //本趟无逆序，停止处理
	}
}
//插入排序,L[begin],L[end]都参与排序
void InsertionSort(int L[], const int begin, const int end)
{
	//按关键码 Key 非递减顺序对表进行排序
	int temp;
	int i, j;
	for (i = begin; i < end; i++)
	{
		if (L[i]>L[i + 1])
		{
			temp = L[i + 1];
			j = i;
			do
			{
				L[j + 1] = L[j];
				if (j == 0)
				{
					j--;
					break;
				}
				j--;

			} while (temp<L[j]);
			L[j + 1] = temp;
		}
	}
}
//n*logn
//快速排序A[startingsub],A[endingsub]都参与排序
void QuickSort(int A[], int startingsub, int endingsub)
{
	if (startingsub >= endingsub)
		;
	else {
		int partition;
		int q = startingsub;
		int p = endingsub;
		int hold;

		do {
			for (partition = q; p > q; p--) {
				if (A[q] > A[p]) {
					hold = A[q];
					A[q] = A[p];
					A[p] = hold;
					break;
				}
			}
			for (partition = p; p > q; q++) {
				if (A[p] < A[q]) {
					hold = A[q];
					A[q] = A[p];
					A[p] = hold;
					break;
				}
			}

		} while (q < p);
		QuickSort(A, startingsub, partition - 1);
		QuickSort(A, partition + 1, endingsub);
	}
}
//希尔排序,L[left],L[right]都参与排序
void Shellsort(int L[], const int left, const int right)
{
	int i, j, gap = right - left + 1;   //增量的初始值
	int temp;
	do {
		gap = gap / 3 + 1;               //求下一增量值
		for (i = left + gap; i <= right; i++)
			//各子序列交替处理
			if (L[i]<L[i - gap]) {        //逆序
				temp = L[i]; j = i - gap;
				do {
					L[j + gap] = L[j];    //后移元素
					j = j - gap;      //再比较前一元素
				} while (j>left&&temp<L[j]);
				L[j + gap] = temp;   //将vector[i]回送
			}
	} while (gap>1);
}
//n
//计数排序,L[n]不参与排序
void CountingSort(int L[], const int n)
{
	int i, j;
	const int k = 1001;
	int tmp[k];
	int *R;
	R = new int[n];
	for (i = 0; i<k; i++) tmp[i] = 0;
	for (j = 0; j<n; j++) tmp[L[j]]++;
	//执行完上面的循环后，tmp[i]的值是L中等于i的元素的个数
	for (i = 1; i<k; i++)
		tmp[i] = tmp[i] + tmp[i - 1]; //执行完上面的循环后，
									  //tmp[i]的值是L中小于等于i的元素的个数
	for (j = n - 1; j >= 0; j--) //这里是逆向遍历，保证了排序的稳定性
	{

		R[tmp[L[j]] - 1] = L[j];
		//L[j]存放在输出数组R的第tmp[L[j]]个位置上
		tmp[L[j]]--;
		//tmp[L[j]]表示L中剩余的元素中小于等于L[j]的元素的个数 

	}
	for (j = 0; j<n; j++) L[j] = R[j];
}
//基数排序
void printArray(const int Array[], const int arraySize);
int getDigit(int num, int dig);
const int radix = 10;   //基数
void RadixSort(int L[], int left, int right, int d) {
	//MSD排序算法的实现。从高位到低位对序列划分，实现排序。d是第几位数，d=1是最低位。left和right是待排序元素子序列的始端与尾端。
	int i, j, count[radix], p1, p2;
	int *auxArray;
	int M = 5;
	auxArray = new int[right - left + 1];
	if (d <= 0) return; //位数处理完递归结束
	if (right - left + 1<M) {//对于小序列可调用直接插入排序
		InsertionSort(L, left, right); return;
	}
	for (j = 0; j<radix; j++) count[j] = 0;
	for (i = left; i <= right; i++) //统计各桶元素的存放位置
		count[getDigit(L[i], d)]++;
	for (j = 1; j<radix; j++) //安排各桶元素的存放位置
		count[j] = count[j] + count[j - 1];
	for (i = right; i >= left; i--) { //将待排序序列中的元素按位置分配到各个桶中，存于助数组auxArray中
		j = getDigit(L[i], d);  //取元素L[i]第d位的值
		auxArray[count[j] - 1] = L[i]; //按预先计算位置存放
		count[j]--;  //计数器减1
	}
	for (i = left, j = 0; i <= right; i++, j++)
		L[i] = auxArray[j];  //从辅助数组顺序写入原数组
	delete[]auxArray;
	for (j = 0; j<radix; j++) { //按桶递归对d-1位处理
		p1 = count[j] + left;  //取桶始端,相对位置，需要加上初值$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		(j + 1 <radix) ? (p2 = count[j + 1] - 1 + left) : (p2 = right); //取桶尾端
																		//	delete []count;
		if (p1<p2) {
			RadixSort(L, p1, p2, d - 1);  //对桶内元素进行基数排序 
										  //  printArray(L,10);
		}
	}

}
int getDigit(int num, int dig)
{
	int myradix = 1;
	/*	for(int i = 1;i<dig;i++)
	{
	myradix *= radix;
	}*/
	switch (dig)
	{
	case 1:
		myradix = 1;
		break;
	case 2:
		myradix = 10;
		break;
	case 3:
		myradix = 1000;
		break;
	case 4:
		myradix = 10000;
		break;
	default:
		myradix = 1;
		break;
	}
	return (num / myradix) % radix;
}
