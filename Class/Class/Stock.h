#ifndef _STOCK00_H_
#define _STOCK00_H_

#include <string>
using namespace std;

class Stock
{
private:
	string company;//��˾����
	long shares;//���ֹ�Ʊ����
	double share_val;//ÿ�ɼ۸�
	double total_val;//��Ʊ��ֵ

	void set_tot() { total_val = share_val * shares; } //����������Ҳ�����ڶ������ͷ�ļ��е��ǲ������ж������£�
public:
	void acquire( const string & co, long n, double pr );//�״ι���
	void buy( long num, double price );//����
	void sell( long num, double price );//����
	void update( double price );//����
	void show();//��ʾ��Ϣ

};

/*
����ֻ������ void set_tot();
���⣺
inline Stock::set_tot()
{
	total_val = share_val * shares;
}
*/
#endif