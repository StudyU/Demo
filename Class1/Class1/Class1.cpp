//Àà×÷ÓÃÓò
#include<iostream>
using namespace std;

class IK
{
private:
	int fuss;
public:
	IK(int f = 9) {fuss = f;}
	void ViewIK() const;
};

void IK::ViewIK() const
{
	cout << fuss << endl;
}
int main()
{
	IK * pik = new IK;
	IK ee = IK(8);
	ee.ViewIK();
	pik->ViewIK();
	return 0;
}