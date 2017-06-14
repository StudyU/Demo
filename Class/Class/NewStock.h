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
	//构造函数
	NewStock();
	NewStock( const string & co, long n = 0, double pr = 0.0 );//为NewStock提供该有的对象值
	~NewStock();//析构函数释放内存
	void buy( long num, double price );//增持
	void sell( long num, double price );//卖出
	void update( double price );//更新
	//void show();//显示信息
	void show() const;//const后置保证函数不会修改调用对象
	//this指针比较总值大小(s参数显式访问，对象调用隐式访问)
	const NewStock & topval( const NewStock & s) const;
};

#endif