#pragma once
/*类中定义,非线程安全*/
#define DEFINE_SINGLETON(a)\
private : a(void) {}; ~a(void) {}; a(const a&) {}; a& operator =(const a&) {};\
public : static a* getInstance() {static a instance; return & instance;};

/*类外定义,非线程安全*/
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
