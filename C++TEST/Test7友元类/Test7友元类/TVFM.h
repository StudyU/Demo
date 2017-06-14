//友元成员函数
//只有Remote类中的一个函数对TV类私有成员有影响
#ifndef TVFM_H_
#define TVFM_H_

class Tv;//前向声明，下面类的顺序必须是这样Remote在TV之前

class Remote
{
private:
	int mode;
public:
	enum{off, on};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cable};//无线和有线
	enum{TV, DVD};

	Remote(int m=TV) : mode(m) {}
	//只能声明不能定义，因为TV类还有没定义，所以定义必须在TV类之后，内联定义
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

//内联函数
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