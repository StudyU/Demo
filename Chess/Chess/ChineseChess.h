#pragma once

class ChineseChess
{
public:
	int type; //1.兵 2.跑 3.车 4.马 5.象 6.士 7.帅 大于7表示无棋子
	bool color; //false（0号玩家） true(1号玩家)
	int x, y;//棋子位置
	ChineseChess();
	virtual ~ChineseChess();
};
