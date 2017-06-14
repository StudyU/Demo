#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;

//ջ�Ƚ����
//���崦��ջ����ģ��ӿ�
template <class T>
class Stack
{
private:
	T stck[SIZE];
	int tos;
public:
	Stack():tos(0) {cout << "Stack initialized!" << endl;}

	~Stack() {cout << "Destory Stack!" << endl;}

	//��ջ
	void push(T);
	//��ջ
	T pop();
};

//��ջ������ջ�ĳ�Ա
template <class T>
void Stack<T>::push(T i)
{
	if(tos==SIZE)
	{
		cout << "The Stack is full!" << endl;
	}
	stck[tos++] = i;
}

template <class T>
T Stack<T>::pop()
{
	if(tos==0)
	{
		cout << "The Stack is underflow!" << endl;
		return 0;
	}
	return stck[--tos];
}

int main()
{
	//int��
	cout << "int �ͣ�";
	Stack<int> n1;
	n1.push(1);
	n1.push(3);
	cout << n1.pop() << endl;
	cout << n1.pop() << endl;

	cout << "string �ͣ�";
	Stack<string> st;
	st.push("You are best!");
	st.push("�����");
	cout << st.pop() << endl;
	cout << st.pop() << endl;


	return 0;
}