#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

int main1()
{
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("Bug is here:[%s] on function: [%s] on line: [%d],%s", __FILE__, __FUNCTION__, __LINE__);
	system("pause");
	return 0;
}

int main2()
{
	int nNum = 1;
	int nKey = 0xff;
	int nQq = 0x100;
	int nQq1 = 0x1000;
	int nResult = nNum & nKey;

	printf("nKey:%d,nResult:%d", nKey, nResult);
	system("pause");

	return 0;
}

int main()
{
	int nNum = 49;
	nNum = nNum << 8;
	int nNew = nNum & 0x0fffff00;
	unsigned int kk = GetTickCount();

	printf("nKey:%d,nResult:%d", nNum, kk);
	system("pause");

	return 0;
}
