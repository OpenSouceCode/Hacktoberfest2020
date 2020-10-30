#include<iostream>
using namespace std;
class integer
{
	int m,n;
	public:
		integer()
		{
			m=0;
			n=0;
		}
		integer(int ,int);
		void display();
};
void integer::display()
{
	cout<<m<<"\n"<<n;
}
integer::integer(int x,int y)
{
	m=x;
	n=y;
}
int main()
{
	integer i1;
	integer i2(10,20);
	integer i3=integer(30,40);
	i1.display();
	cout<<"\n";
	i2.display();
	cout<<"\n";
	i3.display();
	return 0;
}
