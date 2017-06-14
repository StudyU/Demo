#pragma once
//#include "Chess.h"
#include "ChineseChess.h"
#include "NetControl.h"

class Managers
{
public:
	void GameStart();
	bool Domsg(int x, int y, int action);
	int Game_state;
	bool PAUSE;
	ChineseChess LastCh; //��һ���ƶ�������
	ChineseChess *LossCh; //ָ����һ�α��Ե�������
	ChineseChess *PointCh; //���ѡ�����ӣ�ֻ��ѡ�����Ӳ����ƶ�
	ChineseChess nChessinfo[32]; //��¼32��������Ϣ
	int map[9][10]; //��¼�����ϵ���Ϣ
	int PlayerAc; //��ǰ�ĵ�����ң�һ̨��������ʱ�������ã�
	Managers();
	virtual ~Managers();
	bool Game_Type; //��Ϸ���ͣ� false���� true ����
	friend class NetControl;

protected:
	void Updata();
	bool Moveto(int x, int y, bool isgo); //�ж��Ƿ������壨��PointCh�ƶ���map[x][y]λ�ã�
	ChineseChess * Search(int x, int y); //��������������
};
