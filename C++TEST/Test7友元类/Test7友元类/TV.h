#ifndef TV_H_
#define TV_H_
//���ӻ���
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
//ң������
class Remote
{
private:
	int mode;//TV or DVD
public:
	Remote(int m=Tv::TV) : mode(m) {}
	bool volup(Tv &t) {return t.volup();}
	bool voldown(Tv &t) {return t.voldown();}
	void onoff(Tv &t) {return t.onoff();}
	//bool ison(Tv &t) {return t.ison();}
	void chanup(Tv &t) {t.chanup();}
	void chandown(Tv &t) {t.chandown();}
	void set_chan(Tv &t, int n) {t.channel = n;}
	void set_mode(Tv &t) {t.set_mode();}
	void set_input(Tv &t) {t.set_input();}

};
#endif