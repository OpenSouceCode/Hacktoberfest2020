#include<iostream>
using namespace std;
class complex
{
	double x,y;
	public:
		complex()
		{
			x=y=0;
		}
		complex(double a)
		{
			x=y=a;
		}
		complex(double real,double img)
		{
			x=real;
			y=img;
		}
	    void display()
	    {
	    	cout<<x<<"\n"<<y;
		}
		complex sum(complex,complex);
};
complex complex::sum(complex c1,complex c2)
{
	x=c1.x+c2.x;
	y=c1.y+c2.y;
}
int main()
{
	complex a(1.6);
	complex b(2.4,3.8);
	complex c;
	c.sum(a,b);
	a.display();
	cout<<"\n";
	b.display();
	cout<<"\n";
	c.display();
	return 0;
}
