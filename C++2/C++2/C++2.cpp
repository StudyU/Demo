#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int cur_tuple = 0;
	bool next_seq = true;
	const int seq_size = 18;
	const int max_seq = 6;
	int elem_vals[ seq_size ] = {
		1, 2, 3, 3, 4, 7, 2, 5, 12,
		3, 6, 10, 4, 9, 16, 5, 12, 22
	};
	string seq_name[ max_seq ] = {
		"Fi", "Lu", "Pell", "Tri", "Squ", "Pen"
	};
	// elem_vals和elem_vals + seq_size是实际内存位置，标示出“将vector初始化”的元素范围
	//标示出elem_vals内的18个元素，并将它们复制到elem_seq中
	vector<int> elem_seq( elem_vals, elem_vals + seq_size ); 
	while ( next_seq == true && cur_tuple < seq_size )
	{
		cout << "The first two elements of sequence are: "
			<< elem_seq[ cur_tuple ] << ","
			<< elem_seq[ cur_tuple + 1 ] 
		    << "\nWhat is the next elements?\n";
		int usr_guess;
		cin >> usr_guess;
		if ( usr_guess == elem_seq[ cur_tuple + 2 ] )
		{
			cout << "Very good, Yes,"
				<< elem_seq[ cur_tuple + 2 ]
				<< " is the next elements in the "
				<< seq_name[ cur_tuple/3 ] << " Sequence.\n";
				cur_tuple += 3;
		}
		else
		{
			next_seq = false;
			cout << "Error! Can't continue...\n";
		}
	}
	/*
	cout << "The first " << elem_seq.size()
	<< " elements of the Pell Series :\n";
	for (int ix = 0; ix < elem_seq.size(); ++ix)
	{
		cout << elem_seq[ ix ] << ' ';
	}
	cout << '\n';
	*/
	return 0;
}
/*
int main()
{
	const int seq_size = 18;
	int pell_seq[ seq_size ];//arry数组
	//vector<int> pell_seq ( seq_size );
	pell_seq[ 0 ] = 1;
	pell_seq[ 1 ] = 2;

	for ( int ix = 2; ix < seq_size; ++ix )
	{
		pell_seq[ ix ] = pell_seq[ ix - 2 ] + 2 * pell_seq[ ix - 1 ];
	}

	cout << "The first " << seq_size << "elements of the pell series: \n";

	for (int ix = 0; ix < seq_size; ++ix)
	{
		cout << pell_seq[ ix ] << ' ';
	}
	cout << '\n';
	return 0;
}*/