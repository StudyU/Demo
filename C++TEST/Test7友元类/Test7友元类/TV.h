#ifndef TV_H_
#define TV_H_
//电视机类
class Tv
{
private:
	int state;//开关状态
	int volume;//音量
	int maxchannel;//最大频道
	int channel;//当前频道
	int mode;//调节模式
	int input;//TV or DVD
public:
	friend class Remote;//遥控器友元类
	enum{off, on};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cable};//无线和有线
	enum{TV, DVD};

	Tv(int s=off, int mc=125):state(s),volume(MinVal),maxchannel(mc),channel(1),mode(Antenna),input(TV)
	{}
	void onoff() {state = (state == on)?off:on;}
	bool ison() const {return state==on;}
	bool volup();//增大音量
	bool voldown();//降低音量
	void chanup();
	void chandown();
	void set_mode() {mode=(mode==Antenna)?Cable : Antenna;}
	void set_input() {input=(input==TV)?DVD : TV;}
	void setting() const;//display
};
//遥控器类
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