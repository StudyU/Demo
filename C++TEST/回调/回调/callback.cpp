#include"callback.h"
#include <iostream>
using namespace std;

//EventRecord���ʵ��
EventRecord::EventRecord(void)
{
	eventName = NULL;
	pointerToCBO = NULL;
	//��Ϊsizeof(CallBackFunction) > sizeof(CallBackStaticFunction)
	pointerToCBF = NULL;
}
EventRecord::EventRecord(char *ename, CallBack *pCBO, CallBackFunction pCBF):pointerToCBO(pCBO), pointerToCBF(pCBF)
{
	eventName = strdup(ename);
}
EventRecord::EventRecord(char *ename, CallBackStaticFunction pCBSF):pointerToCBO(NULL), pointerToCBSF(pCBSF)
{
	eventName = strdup(ename);
}
EventRecord::~EventRecord(void)
{
	if(eventName) delete eventName;
}
void EventRecord::operator = (const EventRecord& er)
{
	if(er.eventName)
		eventName = strdup(er.eventName);
	else
		eventName = NULL;
	pointerToCBO = er.pointerToCBO;
	pointerToCBF = er.pointerToCBF;
}
int EventRecord::operator == (char *ename) const
{
	if((eventName == NULL)||ename == NULL)
		return eventName == ename;
	else
		return strcmp(eventName,ename) == 0;
}
int EventRecord::operator == (const EventRecord& er) const
{
	return (er == eventName) /*er��eventname���ܽ���λ��*/
		&&(pointerToCBO == er.pointerToCBO)
		&&(pointerToCBO ?
		(pointerToCBF == er.pointerToCBF):
	(pointerToCBSF == er.pointerToCBSF));
}
void EventRecord::Flush(void)
{
	if(eventName){
		delete eventName;
		eventName = NULL;
	}
	pointerToCBO = NULL;
	pointerToCBF = NULL;
}
int EventRecord::IsEmpty(void) const
{
	if(eventName == NULL)
		return 1;
	else
		return 0;
}
//Callback���ʵ��
CallBack::CallBack(void)
{
	//����ʼ�ߴ�Ϊ�ص�������ڴ�ռ�
	callBackList = new EventRecord[CALLBACKLIST_INIT_SIZE];
	if(!callBackList){
		cerr<<"CallBack: memory allocation error."<<endl;
		exit(1);
	}
	size = CALLBACKLIST_INIT_SIZE;
	lastpos = 0;
	curpos = 0;
}
CallBack::CallBack(const CallBack& cb):curpos(cb.curpos),lastpos(cb.lastpos),size(cb.size)
{
	callBackList = new EventRecord[size];
	if(!callBackList){
		cerr<<"CallBack: memory allocation error."<<endl;
		exit(1);
	}
	//һһ���Ƹ����¼���¼
	for(int i = 0; i < size; i++) callBackList[i] = cb.callBackList[i];
}
void CallBack::operator = (const CallBack& cb)
{
	curpos = cb.curpos;
	lastpos = cb.lastpos;
	size = cb.size;
	delete [] callBackList;//ɾ���ɵĻص���
	callBackList = new EventRecord[size];//���·����ڴ�ռ�
	if(!callBackList){
		cerr<<"CallBack: memory allocation error."<<endl;
		exit(1);
	}
	//һһ���Ƹ����¼���¼
	for(int i = 0; i < size; i++) callBackList[i] = cb.callBackList[i];
}
CallBack::~CallBack(void)
{
	delete [] callBackList;
}
void CallBack::AddCallBack(char *event, CallBackFunction pCBF, CallBack *pCBO)
{
	//���¼���Ϊ�գ��˳�
	if( (event == NULL)?1:(strlen(event) == 0)) return;

	//Ѱ����ɾ���¼���¼�������ĵ�һ������λ�ã�����д���¼���¼
	for(int start=0;start<lastpos;start++)
	{
		if(callBackList[start].IsEmpty())
		{
			callBackList[start] = EventRecord(event,pCBO,pCBF);
			return; //ȷʵ���ڿ���λ��
		}
		//if(start < lastpos) return; //ȷʵ���ڿ���λ��
	}

	//û�п���λ�ã��ڻص����׷���¼�¼
	if(lastpos == size) //�ص����������衰�쳤��
	{
		EventRecord *tempList = callBackList;//�ݴ�ɻص���ָ��
		//��һ���Ĳ������쳤���ص���
		callBackList = new EventRecord[size + CALLBACKLIST_INCREMENT];
		if(!callBackList)
		{
			cerr<<"CallBack: memory allocation error."<<endl;
			exit(1);
		}
		//���ƾɻص����еļ�¼
		for(int i = 0; i < size; i++) callBackList[i] = tempList[i];
		delete [] tempList;//ɾ���ɻص���
		size += CALLBACKLIST_INCREMENT;//�����»ص���ĳߴ�
	}
	//�����µ��¼���¼����������ص�����
	callBackList[lastpos] = EventRecord(event,pCBO,pCBF);
	lastpos++;
}
void CallBack::AddCallBack(char *event,CallBackStaticFunction pCBSF)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	for(int start=0;start<lastpos;start++)
	{
		if(callBackList[start].IsEmpty())
		{
			callBackList[start] = EventRecord(event,pCBSF);
			break;
		}
		if(start < lastpos) return; //a hole is found
	}
		if(lastpos == size) //event list is insufficient
		{
			EventRecord *tempList = callBackList;
			callBackList = new EventRecord[size + CALLBACKLIST_INCREMENT];
			if(!callBackList)
			{
				cerr<<"CallBack: memory allocation error."<<endl;
				exit(1);
			}
			for(int i = 0; i < size; i++) callBackList[i] = tempList[i];
			delete [] tempList;
			size += CALLBACKLIST_INCREMENT;
		}
		callBackList[lastpos] = EventRecord(event,pCBSF);
		lastpos++;
}
//ɾ��ע����ָ���¼��ϵĳ�Ա����
void CallBack::RemoveCallBack(char *event, CallBackFunction pCBF, CallBack *pCBO)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	EventRecord er(event,pCBO,pCBF);
	for(int i = 0; i < lastpos; i++)
		if(callBackList[i] == er) callBackList[i].Flush();
}
//ɾ��ע����ָ���¼��ϵľ�̬��Ա��������ͨ����
void CallBack::RemoveCallBack(char *event,CallBackStaticFunction pCBSF)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	EventRecord er(event,pCBSF);
	for(int i = 0; i < lastpos; i++)
		if(callBackList[i] == er) callBackList[i].Flush();
}
//ɾ��ע����ָ���¼��ϵ����лص�����
void CallBack::RemoveCallBack(char *event)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	for(int i = 0; i < lastpos; i++)
		if(callBackList[i] == event) callBackList[i].Flush();
}
void CallBack::CallCallBack(char *event, CallData callData)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	CallBack *pCBO;
	CallBackFunction pCBF;
	CallBackStaticFunction pCBSF;
	MoveFirst();
	while(!EndOfList())
	{
		//�統ǰ�¼���¼��ָ���¼���ƥ�䣬ת����һ����¼����ѭ��
		if(!(callBackList[curpos] == event))
		{
			MoveNext();
			continue;
		}
		//���ҵ�ƥ���¼
		pCBO = callBackList[curpos].pointerToCBO;
		//���¼���¼�лص�����ָ��Ϊ�գ�˵���ü�¼�б�����Ǿ�̬����ָ��
		if(pCBO == NULL){
			pCBSF = callBackList[curpos].pointerToCBSF;
			pCBSF(callData);//���øþ�̬�ص�����
		}
		else //���¼���¼�лص�����ָ��ǿգ�˵���ü�¼�б�����ǳ�Ա����ָ��
		{
			pCBF = callBackList[curpos].pointerToCBF;
			(pCBO->*pCBF)(callData);// ���øûص�����ĳ�Ա����
		}
		MoveNext();
	}
}
