//题目：求 1+2+…+n，
//要求不能使用乘除法、 for、 while、 if、 else、 switch、 case 等关键字以及条件判断语句（A?B:C）
#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <stdio.h>
//#include <sstream>

//?????省去好多不知道对不对
using namespace std;

class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	//static void Reset(){ N = 0; Sum = 0; }
	static int GetSum(){ return Sum; }

private:
	static int N;
	static int Sum;
};
//静态变量初始化
int Temp::N = 0;
int Temp::Sum = 0;

int solutionSum(int n)
{
	//Temp::Reset();
	Temp *a = new Temp[n]; //new出n个数组

	delete []a;
	//a = 0;

	return Temp::GetSum();
}

int main()
{
	cout << "Enter a Num: ";
	int n;
	cin >> n;
	cout << solutionSum(n) << endl;
	return 0;
}