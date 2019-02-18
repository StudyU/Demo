#pragma once
/*���ж���,���̰߳�ȫ*/
#define DEFINE_SINGLETON(a)\
private : a(void) {}; ~a(void) {}; a(const a&) {}; a& operator =(const a&) {};\
public : static a* getInstance() {static a instance; return & instance;};

/*���ⶨ��,���̰߳�ȫ*/
template <class T>
class Singleton
{
public:
	static T* getInstance()
	{
		static T instance;
		return &instance;
	}

private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton<T>&) {};
	Singleton& operator =(const Singleton<T>&) {};
};
