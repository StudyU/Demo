#include<iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//ע���ָ��
int main()
{
/*	const int index = 4;
	int cnt = 0;
	//srand( index );
	for ( int ix = 0; ix < 10; ix++ )
	{
		cnt = rand() % index; // 0--3
		cout << "cnt: " << cnt << endl;
	}*/

	clock_t start, finish;
	start = clock();
	vector<int> fib, luc, pell, tri, squa, pen;
	//type_of_object_pointed_to * name_of_pointer_object;
	//vector<int> *pv = 0;//��Ҫָ��ϵ����ָ��vector<int>������Ϊpv����������ֵ 0��
	const int seq_cnt = 6;
	int seq_index = 0;
	//��ÿ�����е��ڴ��ַ����ĳ��vector��
	//һ��ָ�����飬����Ϊseq_cnt,ÿ��ָ�붼ָ��vector<int> ����
	//Ԫ���ͱ�Ϊvector<int> *��seq_addrs[0]����ֵ�� fib vector �ĵ�ַ
	vector<int> *seq_addrs[ seq_cnt ] = {
		&fib, &luc, &pell, &tri, &squa, &pen
	};

	vector<int> *current_vec = 0;
	for (int ix = 0; ix < seq_cnt; ++ix )
	{
		current_vec = seq_addrs[ ix ];
		cout << current_vec << endl;
	}
	srand( seq_cnt );
	seq_index = rand() % seq_cnt;
	current_vec = seq_addrs[ seq_index ];
	cout << current_vec << endl;

	finish = clock();

	cout << (finish - start) << "/" << CLOCKS_PER_SEC << "(s)" << endl;
	return 0;
}