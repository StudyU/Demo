#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	const int min_size = 4;
	while ( cin >> word )
	{
		if ( word.size() < min_size )
		{
			cout << "xiaoyu 4!" << endl;
			continue;
		}
		else
		{
			cout << "dayu 4!" << endl;
			cout << word
				<<( word.size() % min_size ? '\\': '\n' );
			continue;
		}

	}
	return 0;
}
/*
int main()
{
	bool next_seq = true;//现实下一组数据
	bool go_for_it = true;//用户再猜一次
	bool got_it = false;//用户是否猜对
	static int next_elem = 8;//猜的数
	int num_tries = 0;//用户猜过的总数
	int num_right = 0;//用户猜对的总数
	while ( next_seq == true )
	{
		while ( ( got_it == false ) && ( go_for_it == true ))
		{
			int usr_guess;
			cin >> usr_guess;
			num_tries++;
			if ( usr_guess == next_elem)
			{
				got_it = true;
				num_right++;
				cout << "You get it!" << endl;
			}
			else
			{
				cout << "No！！！ Want to try another sequence? (Y/N):";
				char usr_rsp;
				cin >> usr_rsp;
				if ( usr_rsp == 'N' || usr_rsp == 'n' )
				{
					go_for_it = false;
					cout << "You give up！" <<endl;
				}
			}
		}
	}

	return 0;
}
*/