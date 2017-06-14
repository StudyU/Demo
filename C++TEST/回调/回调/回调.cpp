#include"callback.h"
#include <iostream>
using namespace std;

class Speaker:public CallBack
{
private:
	int volume;
public:
	Speaker(int v): volume(v) {}
	void IncreaseVolume(int v) //����������Ա����
	{
		volume += v;
		if(volume > 20){
			//����������20���¼�������
			//����ע�������¼��ϵĻص�����
			CallCallBack("�����ı���");
			CallCallBack("��������20", &volume);
		}
	}
	void DecreaseVolume(int v) //����������Ա����
	{
		volume -= v;
		if(volume < 5){ //������С��5���¼�������
			//����ע�������¼��ϵĻص�����
			CallCallBack("�����ı���");
			CallCallBack("����С��5", &volume);
		}
	}
};
//�����䡱��
class Ear : public CallBack
{
public:
	static void Response(CallData callData) //�ԡ������ı䡱�ķ�Ӧ
	{
		cout<<"�����ı���."<<endl;
	}
	void HighVoiceResponse(CallData callData)//�Ը����ķ�Ӧ
	{
		cout<<"ι��̫���ˣ����������ǣ�"<<*((int *)callData)<<endl;
	}
	void LowVoiceResponse(CallData callData)// �Ե����ķ�Ӧ
	{
		cout<<"�������������ˡ����������ǣ�"<<*((int *)callData)<<endl;
	}
};
void main(void)
{
	Speaker s(10); //��������Ϊ10
	Ear e;
	//Ϊ�¼�����sע��ص�����
	s.AddCallBack("��������20",(CallBackFunction)&Ear::HighVoiceResponse,&e);
	s.AddCallBack("����С��5",(CallBackFunction)&Ear::LowVoiceResponse,&e);
	s.AddCallBack("�����ı���",(CallBackStaticFunction)&Ear::Response);
	s.IncreaseVolume(12);//����������12����������λ22
	s.DecreaseVolume(20);//����������20����������λ2

}
