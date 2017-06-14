#ifndef _STOCK00_H_
#define _STOCK00_H_

#include <string>
using namespace std;

class Stock
{
private:
	string company;//公司名称
	long shares;//所持股票数量
	double share_val;//每股价格
	double total_val;//股票总值

	void set_tot() { total_val = share_val * shares; } //内联函数，也可以在定义类的头文件中但是不在类中定义如下：
public:
	void acquire( const string & co, long n, double pr );//首次购买
	void buy( long num, double price );//增持
	void sell( long num, double price );//卖出
	void update( double price );//更新
	void show();//显示信息

};

/*
类中只需声明 void set_tot();
类外：
inline Stock::set_tot()
{
	total_val = share_val * shares;
}
*/
#endif