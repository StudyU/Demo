#include<iostream>
#include "Stock.h"

void Stock::acquire(const std::string &co, long n, double pr)
{
	company = co;
	if ( n < 0 )
	{
		cout << "Number of shares can't be negative; "
			<< company << " shares sets to 0.\n";
		shares = 0;	
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if ( num < 0 )
	{
		cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}

}

void Stock::sell(long num, double price)
{
	if ( num < 0 )
	{
		cout << "Number of shares sold can't be negtive. "
			<< "Transaction is aborted.\n";
	}
	else if ( num > shares )
	{
		cout << "You can't sell more then you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}

}

void Stock::update(double price)
{
	share_val = price;
	set_tot();

}
/*
void Stock::show()
{
	cout << "Company: " << company
		<< " Shares: " << shares << '\n'
		<< " Share Price: $" << share_val
		<< " Total Worth: $" << total_val << '\n';

}
*/
//细节修改,避免科学计数法
void Stock::show()
{
	ios_base::fmtflags orig = cout.setf( ios_base::fixed, ios_base::floatfield );
	streamsize prec = cout.precision(3);//3位小数

	cout << "Company: " << company
		<< " Shares: " << shares << '\n'
		<< " Share Price: $" << share_val;

	cout.precision(2);//2位小数
	cout << " Total Worth: $" << total_val << '\n';

	cout.setf( orig, ios_base::floatfield );
	cout.precision(prec);
}
