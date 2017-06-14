#include<iostream>
#include "NewStock.h"

 NewStock::NewStock()
{
	//cout << "Default constructor called\n";
	m_company = "no name";
	m_shares = 0;
	m_share_val = 0.0;
	m_total_val = 0.0;
}
 //构造函数定义
 NewStock::NewStock(const string &co, long n, double pr)
{
	//cout << "Constructor using" << co << " called\n";
	m_company = co;

	if ( n < 0 )
	{
		cout << "Number of m_shares can't be negative; "
			<< m_company << " m_shares sets to 0.\n";
		m_shares = 0;	
	}
	else
	{
		m_shares = n;
	}
	m_share_val = pr;
	m_set_tot();
}

 NewStock::~NewStock()
 {
	// cout << "Bye, " << m_company << "!\n";
 }

void NewStock::buy(long num, double price)
{
	if ( num < 0 )
	{
		cout << "Number of m_shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		m_shares += num;
		m_share_val = price;
		m_set_tot();
	}

}

void NewStock::sell(long num, double price)
{
	if ( num < 0 )
	{
		cout << "Number of m_shares sold can't be negtive. "
			<< "Transaction is aborted.\n";
	}
	else if ( num > m_shares )
	{
		cout << "You can't sell more then you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		m_shares -= num;
		m_share_val = price;
		m_set_tot();
	}

}

void NewStock::update(double price)
{
	m_share_val = price;
	m_set_tot();

}

//细节修改,避免科学计数法 const后置
void NewStock::show() const
{
	ios_base::fmtflags orig = cout.setf( ios_base::fixed, ios_base::floatfield );
	streamsize prec = cout.precision(3);//3位小数

	cout << "m_company: " << m_company
		<< " m_shares: " << m_shares << '\n'
		<< " Share Price: $" << m_share_val;

	//cout.precision(2);//2位小数
	cout << " Total Worth: $" << m_total_val << '\n';

	cout.setf( orig, ios_base::floatfield );
	cout.precision(prec);
}

//this指针和const后置
const NewStock & NewStock::topval(const NewStock & s) const
{
	if ( s.m_total_val > m_total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}