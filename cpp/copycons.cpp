#include<iostream>
using namespace std;
class code
{
	int id;
	public:
		code()
		{
			id=0;
		}
		code(int a)
		{
			id=a;
		}
		code(code &x)
		{
			id=x.id;
		}
		void show()
		{
			cout<<id;
		}
};
int main()
{
	code a(100);
	code b(a);
	code c=a;//calling of copy constructor
	code d;
	d=a;
	a.show();
	cout<<"\n";
	b.show();
	cout<<"\n";
	c.show();
	cout<<"\n";
	d.show();
	return 0;
}
