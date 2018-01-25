#include"callback.h"
#include <iostream>
using namespace std;

//EventRecord类的实现
EventRecord::EventRecord(void)
{
	eventName = NULL;
	pointerToCBO = NULL;
	//因为sizeof(CallBackFunction) > sizeof(CallBackStaticFunction)
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
	return (er == eventName) /*er和eventname不能交换位置*/
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
//Callback类的实现
CallBack::CallBack(void)
{
	//按初始尺寸为回调表分配内存空间
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
	//一一复制各条事件记录
	for(int i = 0; i < size; i++) callBackList[i] = cb.callBackList[i];
}
void CallBack::operator = (const CallBack& cb)
{
	curpos = cb.curpos;
	lastpos = cb.lastpos;
	size = cb.size;
	delete [] callBackList;//删除旧的回调表
	callBackList = new EventRecord[size];//重新分配内存空间
	if(!callBackList){
		cerr<<"CallBack: memory allocation error."<<endl;
		exit(1);
	}
	//一一复制各条事件记录
	for(int i = 0; i < size; i++) callBackList[i] = cb.callBackList[i];
}
CallBack::~CallBack(void)
{
	delete [] callBackList;
}
void CallBack::AddCallBack(char *event, CallBackFunction pCBF, CallBack *pCBO)
{
	//如事件名为空，退出
	if( (event == NULL)?1:(strlen(event) == 0)) return;

	//寻找因删除事件记录而产生的第一个空闲位置，并填写新事件记录
	for(int start=0;start<lastpos;start++)
	{
		if(callBackList[start].IsEmpty())
		{
			callBackList[start] = EventRecord(event,pCBO,pCBF);
			return; //确实存在空闲位置
		}
		//if(start < lastpos) return; //确实存在空闲位置
	}

	//没有空闲位置，在回调表后追加新记录
	if(lastpos == size) //回调表已满，需“伸长”
	{
		EventRecord *tempList = callBackList;//暂存旧回调表指针
		//以一定的步长“伸长”回调表
		callBackList = new EventRecord[size + CALLBACKLIST_INCREMENT];
		if(!callBackList)
		{
			cerr<<"CallBack: memory allocation error."<<endl;
			exit(1);
		}
		//复制旧回调表中的记录
		for(int i = 0; i < size; i++) callBackList[i] = tempList[i];
		delete [] tempList;//删除旧回调表
		size += CALLBACKLIST_INCREMENT;//记下新回调表的尺寸
	}
	//构造新的事件记录并将其填入回调表中
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
//删除注册在指定事件上的成员函数
void CallBack::RemoveCallBack(char *event, CallBackFunction pCBF, CallBack *pCBO)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	EventRecord er(event,pCBO,pCBF);
	for(int i = 0; i < lastpos; i++)
		if(callBackList[i] == er) callBackList[i].Flush();
}
//删除注册在指定事件上的静态成员函数或普通函数
void CallBack::RemoveCallBack(char *event,CallBackStaticFunction pCBSF)
{
	if( (event == NULL)?1:(strlen(event) == 0)) return;
	EventRecord er(event,pCBSF);
	for(int i = 0; i < lastpos; i++)
		if(callBackList[i] == er) callBackList[i].Flush();
}
//删除注册在指定事件上的所有回调函数
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
		//如当前事件记录和指定事件不匹配，转入下一条记录继续循环
		if(!(callBackList[curpos] == event))
		{
			MoveNext();
			continue;
		}
		//如找到匹配记录
		pCBO = callBackList[curpos].pointerToCBO;
		//如事件记录中回调对象指针为空，说明该记录中保存的是静态函数指针
		if(pCBO == NULL){
			pCBSF = callBackList[curpos].pointerToCBSF;
			pCBSF(callData);//调用该静态回调函数
		}
		else //如事件记录中回调对象指针非空，说明该记录中保存的是成员函数指针
		{
			pCBF = callBackList[curpos].pointerToCBF;
			(pCBO->*pCBF)(callData);// 调用该回调对象的成员函数
		}
		MoveNext();
	}
}
