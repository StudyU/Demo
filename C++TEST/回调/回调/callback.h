#ifndef _CALLBACK_H
#define _CALLBACK_H
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define CALLBACKLIST_INIT_SIZE 10
#define CALLBACKLIST_INCREMENT 5
class CallBack;
typedef void *CallData;//�ص�����ָ�����Ͷ���
typedef void (CallBack::*CallBackFunction)(CallData); //ָ��ص���Ա������ָ��
typedef void (*CallBackStaticFunction)(CallData); //ָ��̬��Ա��������ͨ������ָ�����Ͷ���
class EventRecord{
private:
	char *eventName; //�ص��¼�����
	CallBack *pointerToCBO;//ָ��ص������ָ��
	//ָ���Ա������ָ���ָ��̬��Ա����������ͨ������ָ��Ĺ�����
	union{
		CallBackFunction pointerToCBF;
		CallBackStaticFunction pointerToCBSF;
	};
public:
	EventRecord(void); //�¼���¼���ȱʡ���캯��
	//���������Ա�������¼���¼
	EventRecord(char *ename,CallBack *pCBO,CallBackFunction pCBF);
	//���������̬��Ա��������ͨ�������¼���¼
	EventRecord(char *ename,CallBackStaticFunction pCBSF);
	~EventRecord(void);//�����¼���¼
	void operator = (const EventRecord& er);//���ظ�ֵ�����
	//�жϵ�ǰ�¼���¼���¼����Ƿ�Ϊename
	int operator == (char *ename) const;
	//�жϵ�ǰ�¼���¼�Ƿ��ָ���¼���¼���
	int operator == (const EventRecord& er) const;
	void Flush(void); //����ǰ�¼���¼���
	int IsEmpty(void) const;//�ж��¼���¼�Ƿ�Ϊ�գ����¼����Ƿ�Ϊ�գ�
	friend class CallBack; //��CallBack���ܷ���EventRecord��˽�г�Ա��
};
class CallBack {
private:
	EventRecord *callBackList; //�ص��¼���
	int curpos; //��ǰ�¼���¼λ��
	int lastpos; //�ص��������һ����λ��
	int size; //�ص���Ĵ�С
	void MoveFirst(void) { curpos = 0; }//����ǰ��¼��Ϊ��һ����¼
	void MoveNext(void) //����һ����¼��Ϊ��ǰ��¼
	{
		if(curpos == lastpos) return;
		curpos++;
	}
	//�жϻص����Ƿ񱻱�����
	int EndOfList(void) const { return curpos == lastpos; }
public:
	CallBack(void);//���캯��
	CallBack(const CallBack& cb);//�������캯��
	~CallBack(void);//��������
	void operator = (const CallBack& cb);// ���ظ�ֵ�����
	//���ص�����ĳ�Ա��������̬��Ա����������ͨ������
	//ע��Ϊ�¼�����Ļص�����
	void AddCallBack(char *event,CallBackFunction cbf,CallBack *p);
	void AddCallBack(char *event,CallBackStaticFunction cbsf);
	//ɾ��ע����ָ���¼��ϵĻص�����
	void RemoveCallBack(char *event,CallBackFunction cbf,CallBack *p);
	void RemoveCallBack(char *event,CallBackStaticFunction cbsf);
	void RemoveCallBack(char *event);// ɾ��ĳ�¼���ȫ����¼
	//ִ��ע����ĳһ�¼��ϵ����лص�����
	void CallCallBack(char *event, CallData calldata = NULL);
};
#endif
