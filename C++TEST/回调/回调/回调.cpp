#include"callback.h"
#include <iostream>
using namespace std;

class Speaker:public CallBack
{
private:
	int volume;
public:
	Speaker(int v): volume(v) {}
	void IncreaseVolume(int v) //增加音量成员函数
	{
		volume += v;
		if(volume > 20){
			//“音量大于20”事件发生了
			//调用注册在两事件上的回调函数
			CallCallBack("音量改变了");
			CallCallBack("音量大于20", &volume);
		}
	}
	void DecreaseVolume(int v) //降低音量成员函数
	{
		volume -= v;
		if(volume < 5){ //“音量小于5”事件发生了
			//调用注册在两事件上的回调函数
			CallCallBack("音量改变了");
			CallCallBack("音量小于5", &volume);
		}
	}
};
//“耳朵”类
class Ear : public CallBack
{
public:
	static void Response(CallData callData) //对“音量改变”的反应
	{
		cout<<"音量改变了."<<endl;
	}
	void HighVoiceResponse(CallData callData)//对高音的反应
	{
		cout<<"喂！太吵了！现在音量是："<<*((int *)callData)<<endl;
	}
	void LowVoiceResponse(CallData callData)// 对低音的反应
	{
		cout<<"啊！我听不清了。现在音量是："<<*((int *)callData)<<endl;
	}
};
void main(void)
{
	Speaker s(10); //现在音量为10
	Ear e;
	//为事件对象s注册回调函数
	s.AddCallBack("音量大于20",(CallBackFunction)&Ear::HighVoiceResponse,&e);
	s.AddCallBack("音量小于5",(CallBackFunction)&Ear::LowVoiceResponse,&e);
	s.AddCallBack("音量改变了",(CallBackStaticFunction)&Ear::Response);
	s.IncreaseVolume(12);//将音量增加12，现在音量位22
	s.DecreaseVolume(20);//将音量减少20，现在音量位2

}
