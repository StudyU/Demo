//��Ŀ���� 1+2+��+n��
//Ҫ����ʹ�ó˳����� for�� while�� if�� else�� switch�� case �ȹؼ����Լ������ж���䣨A?B:C��
#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <stdio.h>
//#include <sstream>

//?????ʡȥ�ö಻֪���Բ���
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
//��̬������ʼ��
int Temp::N = 0;
int Temp::Sum = 0;

int solutionSum(int n)
{
	//Temp::Reset();
	Temp *a = new Temp[n]; //new��n������

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