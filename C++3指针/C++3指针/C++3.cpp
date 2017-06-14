#include<iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

//注意空指针
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
	//vector<int> *pv = 0;//所要指针系用来指向vector<int>，命名为pv，并给定初值 0；
	const int seq_cnt = 6;
	int seq_index = 0;
	//将每个数列的内存地址存入某个vector中
	//一个指针数组，容量为seq_cnt,每个指针都指向vector<int> 对象
	//元素型别为vector<int> *，seq_addrs[0]所含值是 fib vector 的地址
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