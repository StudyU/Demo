//���÷�Ϊ��ֵ���ã����޸ģ������õ��ã��޸�ֵ����
/*
int count = 1;
int &rec = count;//���ñ��������ʼ��
 ++rec;
*/
#include <iostream>

using namespace std;

int squareByValue( int );//��ֵ����
void squareByReference( int & ); //���õ���

int main()
{
	int x = 2, z = 4;
	cout << "x = " << x << " before squareByValue\n"
		<< " Return Value: " << squareByValue( x ) << endl
		<< "x: " << x << " After squareByValue\n" << endl;
	cout << "z = " << z << " before squareByReference\n" << endl;
	 squareByReference( z );
	cout << "z: " << z << " After squareByReference\n" << endl;

	return 0;	
}

int squareByValue( int a )
{
	return a *= a;//ֵ���ݣ��൱�����⿪�ٵĴ洢��Ԫ�����ı�ԭʼ����X
}

void squareByReference( int &cref )
{
	cref *= cref;//ַ���ݣ��������ֱ����ԭ�����ݵĴ洢��Ԫֱ�Ӳ������ı���Zֵ�����Ե���ǰ��ԭʼ���ݷ����ı�
}