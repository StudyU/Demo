#pragma once

class ChineseChess
{
public:
	int type; //1.�� 2.�� 3.�� 4.�� 5.�� 6.ʿ 7.˧ ����7��ʾ������
	bool color; //false��0����ң� true(1�����)
	int x, y;//����λ��
	ChineseChess();
	virtual ~ChineseChess();
};
