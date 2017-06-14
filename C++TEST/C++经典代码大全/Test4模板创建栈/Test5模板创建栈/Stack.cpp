#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;

//栈先进后出
//定义处理栈的类模板接口
template <class T>
class Stack
{
private:
	T stck[SIZE];
	int tos;
public:
	Stack():tos(0) {cout << "Stack initialized!" << endl;}

	~Stack() {cout << "Destory Stack!" << endl;}

	//进栈
	void push(T);
	//出栈
	T pop();
};

//进栈，定义栈的成员
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
	//int型
	cout << "int 型：";
	Stack<int> n1;
	n1.push(1);
	n1.push(3);
	cout << n1.pop() << endl;
	cout << n1.pop() << endl;

	cout << "string 型：";
	Stack<string> st;
	st.push("You are best!");
	st.push("供电段");
	cout << st.pop() << endl;
	cout << st.pop() << endl;


	return 0;
}