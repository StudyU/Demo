//��Ԫ��Ա����
//ֻ��Remote���е�һ��������TV��˽�г�Ա��Ӱ��
#ifndef TVFM_H_
#define TVFM_H_

class Tv;//ǰ���������������˳�����������Remote��TV֮ǰ

class Remote
{
private:
	int mode;
public:
	enum{off, on};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cable};//���ߺ�����
	enum{TV, DVD};

	Remote(int m=TV) : mode(m) {}
	//ֻ���������ܶ��壬��ΪTV�໹��û���壬���Զ��������TV��֮����������
	bool volup(Tv &t); 
	bool voldown(Tv &t); 
	void onoff(Tv &t); 
	//bool ison(Tv &t); 
	void chanup(Tv &t); 
	void chandown(Tv &t); 
	void set_chan(Tv &t, int n); 
	void set_mode(Tv &t);  
	void set_input(Tv &t); 
};
class Tv
{
private:
	int state;//����״̬
	int volume;//����
	int maxchannel;//���Ƶ��
	int channel;//��ǰƵ��
	int mode;//����ģʽ
	int input;//TV or DVD
public:
	friend class Remote;//ң������Ԫ��
	enum{off, on};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cable};//���ߺ�����
	enum{TV, DVD};

	Tv(int s=off, int mc=125):state(s),volume(MinVal),maxchannel(mc),channel(1),mode(Antenna),input(TV)
	{}
	void onoff() {state = (state == on)?off:on;}
	bool ison() const {return state==on;}
	bool volup();//��������
	bool voldown();//��������
	void chanup();
	void chandown();
	void set_mode() {mode=(mode==Antenna)?Cable : Antenna;}
	void set_input() {input=(input==TV)?DVD : TV;}
	void setting() const;//display
};

//��������
inline bool Remote::volup(Tv &t) {return t.volup();}
inline bool Remote::voldown(Tv &t) {return t.voldown();}
inline void Remote::onoff(Tv &t) {return t.onoff();}
//bool ison(Tv &t) {return t.ison();}
inline void Remote::chanup(Tv &t) {t.chanup();}
inline void Remote::chandown(Tv &t) {t.chandown();}
inline void Remote::set_chan(Tv &t, int n) {t.channel = n;}
inline void Remote::set_mode(Tv &t) {t.set_mode();}
inline void Remote::set_input(Tv &t) {t.set_input();}
#endif