#ifndef _CALLBACK_H
#define _CALLBACK_H
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define CALLBACKLIST_INIT_SIZE 10
#define CALLBACKLIST_INCREMENT 5
class CallBack;
typedef void *CallData;//回调数据指针类型定义
typedef void (CallBack::*CallBackFunction)(CallData); //指向回调成员函数的指针
typedef void (*CallBackStaticFunction)(CallData); //指向静态成员函数或普通函数的指针类型定义
class EventRecord{
private:
	char *eventName; //回调事件名称
	CallBack *pointerToCBO;//指向回调对象的指针
	//指向成员函数的指针和指向静态成员函数（或普通函数）指针的共用体
	union{
		CallBackFunction pointerToCBF;
		CallBackStaticFunction pointerToCBSF;
	};
public:
	EventRecord(void); //事件记录类的缺省构造函数
	//构造包含成员函数的事件记录
	EventRecord(char *ename,CallBack *pCBO,CallBackFunction pCBF);
	//构造包含静态成员函数或普通函数的事件记录
	EventRecord(char *ename,CallBackStaticFunction pCBSF);
	~EventRecord(void);//析构事件记录
	void operator = (const EventRecord& er);//重载赋值运算符
	//判断当前事件记录的事件名是否为ename
	int operator == (char *ename) const;
	//判断当前事件记录是否和指定事件记录相等
	int operator == (const EventRecord& er) const;
	void Flush(void); //将当前事件记录清空
	int IsEmpty(void) const;//判断事件记录是否为空（即事件名是否为空）
	friend class CallBack; //让CallBack类能访问EventRecord的私有成员；
};
class CallBack {
private:
	EventRecord *callBackList; //回调事件表
	int curpos; //当前事件记录位置
	int lastpos; //回调表中最后一空闲位置
	int size; //回调表的大小
	void MoveFirst(void) { curpos = 0; }//将当前记录置为第一条记录
	void MoveNext(void) //将下一条记录置为当前记录
	{
		if(curpos == lastpos) return;
		curpos++;
	}
	//判断回调表是否被遍历完
	int EndOfList(void) const { return curpos == lastpos; }
public:
	CallBack(void);//构造函数
	CallBack(const CallBack& cb);//拷贝构造函数
	~CallBack(void);//析构函数
	void operator = (const CallBack& cb);// 重载赋值运算符
	//将回调对象的成员函数、静态成员函数（或普通函数）
	//注册为事件对象的回调函数
	void AddCallBack(char *event,CallBackFunction cbf,CallBack *p);
	void AddCallBack(char *event,CallBackStaticFunction cbsf);
	//删除注册在指定事件上的回调函数
	void RemoveCallBack(char *event,CallBackFunction cbf,CallBack *p);
	void RemoveCallBack(char *event,CallBackStaticFunction cbsf);
	void RemoveCallBack(char *event);// 删除某事件的全部记录
	//执行注册在某一事件上的所有回调函数
	void CallCallBack(char *event, CallData calldata = NULL);
};
#endif
