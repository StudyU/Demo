#include <stdio.h>
#include <string>
using namespace std;
/*
Function templates ������Բ�ͬ�� template arguments ����һ���壨a family of��������
Function templates �����մ��ݶ������Ա�����arguments�������Ͷ���ʵ������instantiated����16
�������ȷָ�� template parameters��
Function templates ���Ա����أ�overloaded����
���� function templates ʱ����ͬ��������ʽ֮�����ֻ���ڡ����Ա�Ҫ�Ĳ��졹��
��ȷ��������ʽ�����غ�������д�����ǵı����õ�֮ǰ��

1. �������Ա���ת��Ϊ��ͬ���ͣ�
max(static_cast<double>(4), 4.2); // OK
2. ��ȷָ�� T�����ͣ�
max<double>(4, 4.2);

���غ���ģ�壺non-template function(���溯��) ���Ժ�ͬ���� function template(����ģ��) ���棬Ҳ���Ժ�����ͬ����
�ľ����干�档������Ҫ�ض����ʱ�����ؽ������ƻ�����ѡ�� non-template function������ѡ
���� function template ʵ������ĺ���ʵ��

�������غ�����ʹ��by reference��ʽ�������Ա���������Ҫ��ͬ
���ǰ�������ʽ�����غ���д�����Ǳ�����֮ǰ��
*/
/********************************���غ���ģ��*********************************/
//non-template function A
inline int const& Max(int const& a, int const& b)
{
	return a > b ? a : b;
}

// function template A1������
template <typename T> 
inline T const& Max(T const& a, T const& b)
{
	return a > b ? a : b;
}

// ��ֵ�����ǻ��������Ҫ�Ŀ���
template <typename T>
inline T const Max1(T const a, T const b)
{
	return a > b ? a : b;
}

// function template A2
template <typename T>
inline T const& Max(T const& a, T const& b, T const& c)
{
	return Max(::Max(a, b), c);
}

int main1()
{
	int i = 1;
	int j = 2;
	string str1 = "hh";
	string str2 = "2231";
	int k = ::Max(i, j);// A
	int kk = ::Max<>(i, j);// A1
	int kkk = ::Max(i, j, 3);// A2
	string str = ::Max(str1, str2);// A2
								   //::Max("ssw", "hig1");	// �������ô�ֵ�ַ������泤�Ȳ�ͬ���ײ��array���;Ͳ�ͬ
	::Max1("ssw", "hig1");	// ��ֵ,�˻�Ϊ��ͬ���ͣ�ֻ�е����� by value ��ʽʹ���ַ������泣����string literals��ʱ���ַ����ײ��� array ��
							// �ᱻת �ͣ��˻���Ϊһ���ַ�ָ�루Ҳ���Ƿ��� "array-to-pointer" ת������
	return 0;
}
/********************************���غ���ģ��*********************************/

/********************************ģ�����*********************************/
/*
1. local classes �� local enum types���༴�����ں��������ڲ��� classes �� enums��
������Ϊtemplate type arguments ʹ�á�
2. ���ĳ�� type �漰�����ģ�unnamed��class types �������ģ�unnamed��enum types�������� type
������Ϊ template type arguments ʹ�ã� ��������� typedefʹ������� ������� template
type arguments��
*/

template <typename T>
class List
{

};

// typedefʹĳ�� unnamed type ��������
typedef struct
{
	float x;
	float y;
} Point;

typedef enum ne {red, greed, blue} *ColorPtr;

int main2()
{
	//��ע������һ�������ں����ڲ�����ν local type
	struct Asso
	{
		int* p;
		int* q;
	};

	List<Asso*> error1;	// ERROR�� template argument �����Ǹ� local type
	List<ColorPtr> error2;	// ERROR�� template argument �����Ǹ� unnamed type
	List<Point> OK;			// OK��ԭ�������� type �� typedef����������

	return 0;
}

template <typename T>
void clear(T p)
{
//	*p = 0;	// unary operator* �����ʩ���� T����
}

int main3()
{
	int i = 1;
	clear(i);	// ERROR�� int����֧�� unary operator*

	return 0;
}

template <typename T, T nontype_param>
class C;

class Base {
public:
	int i;
} base;

class Derived : public Base
{

} derObj;

int main()
{
	Base* p = new Base();
	p->i = 1;
	C<Base*, &base>* k;		// ok
	//C<Base*, &derObj>* kk;	// ERROR����derived-to-base ת������������
	//C<int, p->i>* hh;		// ERROR����Ա������������

	//int a[10];
	//C<int*, a[0]>* gg;		// ERROR������ʹ�� array��ĳ��Ԫ�صĵ�ַ
	return 0;
}

/********************************ģ�����*********************************/

