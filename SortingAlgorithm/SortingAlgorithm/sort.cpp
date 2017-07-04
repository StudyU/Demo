/*
�ȶ��������㷨��

ð������bubble sort�� �� O(n2)

��β������(Cocktail sort, ˫���ð������) �� O(n2)

�������� ��insertion sort���� O(n2)

Ͱ���� ��bucket sort���� O(n); ��Ҫ O(k) ���� ������

�鲢���� ��merge sort���� O(n log n); ��Ҫ O(n) ���������

ԭ�ع鲢���� �� O(n2)

���������� ��Binary tree sort�� �� O(n log n); ��Ҫ O(n) ���������

�������� ��radix sort���� O(n��k); ��Ҫ O(n) ���������


���ȶ��������㷨��

ѡ������ ��selection sort���� O(n2)

ϣ������ ��shell sort���� O(n log n) ���ʹ����ѵ����ڰ汾

Comb sort �� O(n log n)

������ ��heapsort���� O(n log n)

Smoothsort �� O(n log n)

�������� ��quicksort���� O(n log n) ����ʱ��, O(n2) ����; ��춴�ġ���������һ��������������֪����

һ����˵�����ڲ����ڽ����������㷨�ǲ��ȶ��ģ����ڽ����������㷨���ȶ��ģ��������ڽ������ȶ������㷨��ͨ�����ƽ�����������ת���ɲ��ȶ������㷨��ð�ݡ����롢�鲢�ͻ����������ȶ��ģ�ѡ�񡢿��١�ϣ���Ͷ������ǲ��ȶ��ġ�
*/

//n^2
//ð������V[n]����������
void BubbleSort(int V[], int n)
{
	bool exchange;	     //���ý�����־��
	for (int i = 0; i < n; i++) {
		exchange = false;
		for (int j = n - 1; j>i; j--) { //�����⣬����Ƿ�����
			if (V[j - 1] > V[j]) //�������򣬽�������Ԫ��
			{
				int temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
				exchange = true;//������־��λ
			}
		}

		if (exchange == false)
			return; //����������ֹͣ����
	}
}
//��������,L[begin],L[end]����������
void InsertionSort(int L[], const int begin, const int end)
{
	//���ؼ��� Key �ǵݼ�˳��Ա��������
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
//��������A[startingsub],A[endingsub]����������
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
//ϣ������,L[left],L[right]����������
void Shellsort(int L[], const int left, const int right)
{
	int i, j, gap = right - left + 1;   //�����ĳ�ʼֵ
	int temp;
	do {
		gap = gap / 3 + 1;               //����һ����ֵ
		for (i = left + gap; i <= right; i++)
			//�������н��洦��
			if (L[i]<L[i - gap]) {        //����
				temp = L[i]; j = i - gap;
				do {
					L[j + gap] = L[j];    //����Ԫ��
					j = j - gap;      //�ٱȽ�ǰһԪ��
				} while (j>left&&temp<L[j]);
				L[j + gap] = temp;   //��vector[i]����
			}
	} while (gap>1);
}
//n
//��������,L[n]����������
void CountingSort(int L[], const int n)
{
	int i, j;
	const int k = 1001;
	int tmp[k];
	int *R;
	R = new int[n];
	for (i = 0; i<k; i++) tmp[i] = 0;
	for (j = 0; j<n; j++) tmp[L[j]]++;
	//ִ���������ѭ����tmp[i]��ֵ��L�е���i��Ԫ�صĸ���
	for (i = 1; i<k; i++)
		tmp[i] = tmp[i] + tmp[i - 1]; //ִ���������ѭ����
									  //tmp[i]��ֵ��L��С�ڵ���i��Ԫ�صĸ���
	for (j = n - 1; j >= 0; j--) //�����������������֤��������ȶ���
	{

		R[tmp[L[j]] - 1] = L[j];
		//L[j]������������R�ĵ�tmp[L[j]]��λ����
		tmp[L[j]]--;
		//tmp[L[j]]��ʾL��ʣ���Ԫ����С�ڵ���L[j]��Ԫ�صĸ��� 

	}
	for (j = 0; j<n; j++) L[j] = R[j];
}
//��������
void printArray(const int Array[], const int arraySize);
int getDigit(int num, int dig);
const int radix = 10;   //����
void RadixSort(int L[], int left, int right, int d) {
	//MSD�����㷨��ʵ�֡��Ӹ�λ����λ�����л��֣�ʵ������d�ǵڼ�λ����d=1�����λ��left��right�Ǵ�����Ԫ�������е�ʼ����β�ˡ�
	int i, j, count[radix], p1, p2;
	int *auxArray;
	int M = 5;
	auxArray = new int[right - left + 1];
	if (d <= 0) return; //λ��������ݹ����
	if (right - left + 1<M) {//����С���пɵ���ֱ�Ӳ�������
		InsertionSort(L, left, right); return;
	}
	for (j = 0; j<radix; j++) count[j] = 0;
	for (i = left; i <= right; i++) //ͳ�Ƹ�ͰԪ�صĴ��λ��
		count[getDigit(L[i], d)]++;
	for (j = 1; j<radix; j++) //���Ÿ�ͰԪ�صĴ��λ��
		count[j] = count[j] + count[j - 1];
	for (i = right; i >= left; i--) { //�������������е�Ԫ�ذ�λ�÷��䵽����Ͱ�У�����������auxArray��
		j = getDigit(L[i], d);  //ȡԪ��L[i]��dλ��ֵ
		auxArray[count[j] - 1] = L[i]; //��Ԥ�ȼ���λ�ô��
		count[j]--;  //��������1
	}
	for (i = left, j = 0; i <= right; i++, j++)
		L[i] = auxArray[j];  //�Ӹ�������˳��д��ԭ����
	delete[]auxArray;
	for (j = 0; j<radix; j++) { //��Ͱ�ݹ��d-1λ����
		p1 = count[j] + left;  //ȡͰʼ��,���λ�ã���Ҫ���ϳ�ֵ$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		(j + 1 <radix) ? (p2 = count[j + 1] - 1 + left) : (p2 = right); //ȡͰβ��
																		//	delete []count;
		if (p1<p2) {
			RadixSort(L, p1, p2, d - 1);  //��Ͱ��Ԫ�ؽ��л������� 
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
