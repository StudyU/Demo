#include "TVFM.h"
#include <iostream>
using namespace std;

bool Tv::volup()
{
	if (volume<MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume>MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel<maxchannel)
	{
		channel++;
	}
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel>1)
	{
		channel--;
	}
	else
		channel=maxchannel;
}

void Tv::setting() const
{
	cout << "TV is " << ((state==off)?"off" : "on")<< endl;
	if (state==on)
	{
		cout << "volume setting= " << volume <<endl;
		cout << "channel setting= " << channel << endl;
		cout << "mode= " << ((mode==Antenna)?"Antenna":"Cable") << endl;
		cout << "Input= " << ((input==TV)?"TV":"DVD") << endl;
	}
}