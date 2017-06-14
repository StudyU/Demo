#ifndef _NEWSTOCK_H_
#define _NEWSTOCK_H_
#include <string>
using namespace std;

class NewStock
{
private:
	string m_company;
	long m_shares;
	double m_share_val;
	double m_total_val;
	void m_set_tot() { m_total_val = m_share_val * m_shares; }
public:
	//���캯��
	NewStock();
	NewStock( const string & co, long n = 0, double pr = 0.0 );//ΪNewStock�ṩ���еĶ���ֵ
	~NewStock();//���������ͷ��ڴ�
	void buy( long num, double price );//����
	void sell( long num, double price );//����
	void update( double price );//����
	//void show();//��ʾ��Ϣ
	void show() const;//const���ñ�֤���������޸ĵ��ö���
	//thisָ��Ƚ���ֵ��С(s������ʽ���ʣ����������ʽ����)
	const NewStock & topval( const NewStock & s) const;
};

#endif