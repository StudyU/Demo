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
	bool next_seq = true;//��ʵ��һ������
	bool go_for_it = true;//�û��ٲ�һ��
	bool got_it = false;//�û��Ƿ�¶�
	static int next_elem = 8;//�µ���
	int num_tries = 0;//�û��¹�������
	int num_right = 0;//�û��¶Ե�����
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
				cout << "No������ Want to try another sequence? (Y/N):";
				char usr_rsp;
				cin >> usr_rsp;
				if ( usr_rsp == 'N' || usr_rsp == 'n' )
				{
					go_for_it = false;
					cout << "You give up��" <<endl;
				}
			}
		}
	}

	return 0;
}
*/