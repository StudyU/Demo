/**
* @Title  �������Թ�����չ̽��
* @Author ����
* @Date   2013-11-16
* @At     XUST
* @All Copyright by ����
*
*/

#include <iostream>
#include <windows.h>
using namespace std;

int maze[9][9] = { // ��ʼ���Թ���Ӣ��mazeΪ���Թ���
	{ 2,2,2,2,2,2,2,2,2 },
	{ 2,0,0,0,0,0,0,0,2 },
	{ 2,0,2,2,0,2,2,0,2 },
	{ 2,0,2,0,0,2,0,0,2 },
	{ 2,0,2,0,2,0,2,0,2 },
	{ 2,0,0,0,0,0,2,0,2 },
	{ 2,2,0,2,2,0,2,2,2 },
	{ 2,0,0,0,0,0,0,0,2 },
	{ 2,2,2,2,2,2,2,2,2 }
};

int startI = 1, startJ = 1; // �����������
int endI = 7, endJ = 7;     // ������������

void visit(int i, int j)  // �Զ���Ѱ·��
{
	int m, n;

	maze[i][j] = 1;
	static int count = 0;
	count++;

	if ((i == endI) && (j == endJ))
	{
		cout << endl << "��ʾ·��:" << endl;
		for (m = 0; m<9; m++)
		{
			for (n = 0; n<9; n++)
			{
				if (maze[m][n] == 2)
					cout << "��";
				else if (maze[m][n] == 1)
					cout << "��";
				else
					cout << "  ";
			}
			cout << endl;
		}
		cout << --count << endl;
		count = 0;
	}

	if (maze[i][j + 1] == 0)
		visit(i, j + 1);
	if (maze[i + 1][j] == 0)
		visit(i + 1, j);
	if (maze[i][j - 1] == 0)
		visit(i, j - 1);
	if (maze[i - 1][j] == 0)
		visit(i - 1, j);

	maze[i][j] = 0;

}

int main(void)
{
	int i, j;

	cout << "��ʾ�Թ�: " << endl;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			if (maze[i][j] == 2)
				cout << "��";
			else
				cout << "  ";
		}
		cout << endl;
	}

	visit(startI, startJ);

	system("pause");
	return 0;
}

