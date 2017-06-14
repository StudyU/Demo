//��ͽṹ�壬Բ���������.����ͨ��������������������÷��ʽṹ��Ա�����Ա����ͷ��������->����ͨ������ָ����ʽṹ��Ա�����Ա
//��timeObjectΪ�ṹ�� timePtr = &timeObject; cout << timePtr->hour��(*timePtr).hour; ��.�����ȼ����ڣ�*��;


//ʱ���ж�
#include<iostream>
using namespace std;

//�ṹ��
struct Time
{
	int hour;
	int minute;
	int second;
};

//����ԭ��
//�ṹͨ��ͨ����ֵ���ô��ݣ�����Ϊ�˱��⸴�ƽṹ�Ŀ�����ʹ�����õ��ô��ݽṹ����
void PrintMilitary( const Time &);
void PrintStandard( const Time &);

int main()
{
	Time dinnerTime;
	dinnerTime.hour = 18;
	dinnerTime.minute = 30;
	dinnerTime.second = 0;

	cout << "Dinner will be held at ";
	PrintMilitary( dinnerTime );
	cout << " Military time,\nwhich is ";
	PrintStandard( dinnerTime );
	cout << " Standard time.\n";

	dinnerTime.hour = 29;
	dinnerTime.minute = 73;
	
	cout << "\nTime with invaild values: ";
	PrintMilitary( dinnerTime );
	cout << endl;
	return 0;
}

void PrintMilitary( const Time &t )
{
	cout << ( t.hour < 10 ? "0":"" ) << t.hour << ":"
		<< ( t.minute < 10 ? "0":"" ) << t.minute;
}

void PrintStandard( const Time &t )
{
	cout << (( t.hour == 0 || t.hour == 12 ) ? 12 : t.hour % 12 )
		<< ":" << ( t.minute < 10 ? "0":"" ) << t.minute 
		<< ":" << ( t.second < 10 ? "0":"" ) << t.second
		<< ( t.hour < 12 ? " Am" : " PM" );
}