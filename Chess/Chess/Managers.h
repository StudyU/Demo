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
	ChineseChess LastCh; //上一次移动的棋子
	ChineseChess *LossCh; //指向上一次被吃掉的棋子
	ChineseChess *PointCh; //玩家选中棋子，只有选中棋子才能移动
	ChineseChess nChessinfo[32]; //记录32个棋子信息
	int map[9][10]; //记录棋盘上的信息
	int PlayerAc; //当前的电脑玩家（一台机器运行时不起作用）
	Managers();
	virtual ~Managers();
	bool Game_Type; //游戏类型， false单机 true 联网
	friend class NetControl;

protected:
	void Updata();
	bool Moveto(int x, int y, bool isgo); //判断是否能走棋（把PointCh移动到map[x][y]位置）
	ChineseChess * Search(int x, int y); //根据坐标获得棋子
};
