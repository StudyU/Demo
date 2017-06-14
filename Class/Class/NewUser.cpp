#include <iostream>
#include "NewStock.h"

//对象数组
const int STKS = 6;

int main()
{
	NewStock stocks[STKS] = {
		NewStock("NanoSmart", 12, 20.0),
		NewStock(),
		NewStock("Boffo Objects", 200, 2.0),
		NewStock("Monolithic Obelisks", 130, 3.25),
		NewStock("Fleep Enterprises", 60, 6.5)
	};

	cout << "NewStock holdings:\n";
	int st;
	for( st = 0; st < STKS; st++ )
	{
		stocks[st].show();
	}

	const NewStock * top = &stocks[0];
	for( st = 1; st < STKS; st++ )
	{
		top = &top->topval(stocks[st]);
	}

	cout << "\nMost valuable holdingt:\n";
	top->show();
	return 0;
}


/*
int main()
{
	{
		cout << "Using constructors to create new object\n";
		NewStock stock1( "NanoSmart", 12, 20.0 );
		stock1.show();
		NewStock stock2( "Boffo Objects", 2, 2.0 );
		stock2.show();

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = NewStock( "Nifty Foods", 10, 50.0 );
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";
	}
	return 0;
}
*/