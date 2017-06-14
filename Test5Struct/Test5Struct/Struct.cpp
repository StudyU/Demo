#include <iostream>
using namespace std;

struct ItemLog
{
	ItemLog()
		:eventID(0),eventtype(0),ItemID(""),itemNum(0)
	{}
	int eventID;
	int eventtype;
	const char *ItemID;
	int itemNum;
};

int main()
{
	ItemLog itemlog;
	itemlog.eventID = 177236;
	itemlog.eventtype = 1;
	itemlog.ItemID = "Manster0001";
	itemlog.itemNum = 90;

	cout << itemlog.eventID << endl;

	return 0;
}