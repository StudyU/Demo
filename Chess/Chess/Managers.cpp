#include "StdAfx.h"
#include "Managers.h"

Managers::Managers(void)
{
}

Managers::~Managers(void)
{
}

/*
函数名称：GameStart()
函数介绍：初始化函数
输入参数：无
输出参数：无
返回值：无
*/
/*
void Managers::GameStart()
{
	int i, j;
	for( i = 0; i < 9; i++ )
	{
		for ( j = 0; j < 10; j++ )
		{
			map[i][j] = 0;
		}
	}

	for ( i = 0; i < 16; i++ )
	{
		nChessinfo[i].color = true;
	}

	for ( i = 16; i < 32; i++ )
	{
		nChessinfo[i].color = false;
	}

	for ( i = 16; i < 21; i++)
	{
		map[(i-16)*2][3] = 1;
		nChessinfo[i].type = 1;
		nChessinfo[i].x = (i-16)*2;
		nChessinfo[i].y = 3;
	}

	map[1][7] = 2;
	map[7][7] = 2;
	nChessinfo[5].type = 2; //炮1
	nChessinfo[5].x = 1;
	nChessinfo[5].y = 7;
	nChessinfo[6].type = 2; //炮2
	nChessinfo[6].x = 7;
	nChessinfo[6].y = 7;
	for( i = 7; i < 16; i++ )
	{
		nChessinfo[i].y = 9;
	}
	nChessinfo[7].type = 3; //车1
	nChessinfo[7].x = 0;
	nChessinfo[8].type = 3; //车2
	nChessinfo[8].x = 8;
	nChessinfo[9].type = 4; //马1
	nChessinfo[9].x = 1;
	nChessinfo[10].type = 4; //马2
	nChessinfo[10].x = 7;
	nChessinfo[11].type = 5; //相1
	nChessinfo[11].x = 2;
	nChessinfo[12].type = 5; //相2
	nChessinfo[12].x = 6;
	nChessinfo[13].type = 6; //士1
	nChessinfo[13].x = 3;
	nChessinfo[14].type = 6; //士2
	nChessinfo[14].x = 5;
	nChessinfo[15].type = 7; //帅1
	nChessinfo[15].x = 4;

	for ( i = 0; i < 9; i++ )
	{
		map[i][0] = 1;
		map[i][9] = 2;
	}
	map[1][2] = 1;
	map[7][2] = 1;
	nChessinfo[21].type = 2; //炮3
	nChessinfo[21].x = 1;
	nChessinfo[21].y = 2;
	nChessinfo[22].type = 2; //炮4
	nChessinfo[22].x = 7;
	nChessinfo[22].y = 2;
	for( i = 23; i < 32; i++ )
	{
		nChessinfo[i].y = 0;
	}
	nChessinfo[23].type = 3; //车3
	nChessinfo[23].x = 0;
	nChessinfo[24].type = 3; //车4
	nChessinfo[24].x = 8;
	nChessinfo[25].type = 4; //马3
	nChessinfo[25].x = 1;
	nChessinfo[26].type = 4; //马4
	nChessinfo[26].x = 7;
	nChessinfo[27].type = 5; //相3
	nChessinfo[27].x = 2;
	nChessinfo[28].type = 5; //相4
	nChessinfo[28].x = 6;
	nChessinfo[29].type = 6; //士3
	nChessinfo[29].x = 3;
	nChessinfo[30].type = 6; //士4
	nChessinfo[30].x = 5;
	nChessinfo[31].type = 7; //将2
	nChessinfo[31].x = 4;

	PointCh = NULL;
	PAUSE = false;
	Game_state = 0;
	LossCh = NULL;
	
}
*/
/*
函数名称：DoMsg( int x, int y, int action)
函数介绍: 用户响应函数
输入参数：(x, y)棋盘位置， action 动作，0 鼠标经过 1 鼠标左键
输出参数：无
返回值：无
*/
/*
bool Managers::Domsg(int x, int y, int action)
{
	if(PAUSE)
	{
		return false;
	}
	if ( Game_state < 0 || Game_state > 1 )
	{
		return false;
	}
	if ( action == 1 && (Game_state == PlayerAc || !Game_Type))
	{
		if ( PointCh == NULL )
		{
			if ( map[x][y] - 1 ==Game_state )
			{
				PointCh = Search(x, y);
				return true;
			}
			else
			{
				return false;
			}
		}
		else if ( ( PointCh->color && Game_state == 1 ) || ( !PointCh->color && Game_state == 0 ) )
		{
			if ( PointCh->x == x && PointCh->y == y )
			{
				PointCh = NULL;
				return true;
			}
			else if ( Moveto(x, y, true))
			{
				Updata();
				return true;
			}
			else if ( map[x][y] == Game_state + 1 )
			{
				PointCh = Search(x, y);
				return true;
			}
			else
			{
				PointCh = NULL;
				return false;
			}
		}
		else
		{
			PointCh = NULL;
			return false;
		}
	}
	else if ( action == 0 && (Game_state == PlayerAc || !Game_Type) )
	{
		if ( PointCh != NULL )
		{
			if ( Moveto(x, y, true) )
			{
				return true;
			}

		}

	}
	return false;
}
*/
/*
函数名称：Moveto( int x, int y, bool isgo )
函数介绍: 棋子移动函数
输入参数：(x, y)棋盘位置， isgo 是否可移动
输出参数：无
返回值：无
*/
/*
bool Managers::Moveto( int x, int y, bool isgo )
{
	if ( PointCh == NULL )
	{
		return false;
	}

	ChineseChess &ch = *PointCh;
	if ( (map[x][y] == 1 && !ch.color) || (map[x][y] == 2 && ch.color))
	{
		return false;
	}

	if ( ch.type == 1 ) //兵
	{
		if ( (abs(ch.x-x) == 1 && ch.y == 1) || (abs(ch.y-y) == 1 && ch.x == 1))
		{
			if (!ch.color && ch.y < 5 && ch.x != x)
			{
				return false;
			}
			if (!ch.color && ch.y > 4 && ch.x != x)
			{
				return false;
			}
			if (!ch.color && y < ch.y)
			{
				return false;
			}
			if (ch.color && y > ch.y)
			{
				return false;
			}
			if (isgo)
			{
				LastCh = ch;
				map[ch.x][ch.y] = 0;
				if (map[x][y] > 0)
				{
					LossCh = Search(x, y);
				}
				if (ch.color)
				{
					map[x][y] = 2;
				}
				else
				{
					map[x][y] = 1;
				}
				ch.x = x;
				ch.y = y;
				return true;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (ch.type == 2) //炮
	{
		if (( ch.x != x && ch.y != y) || (ch.x == x && ch.y == y))
		{
			return false;
		}

		int i = ch.x - x, j = ch.y - y;
		if ( i > 0)
		{
			i--;
		}
		else if ( i < 0 )
		{
			i++;
		}
		if ( j > 0 )
		{
			j--;
		}
		else if ( j < 0 )
		{
			j++;
		}

		int num = 0;

	}

}
*/