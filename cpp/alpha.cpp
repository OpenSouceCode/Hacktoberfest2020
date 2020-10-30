#include<iostream>
using namespace std;
int count=0;
class alpha
{
	public:
		alpha()
		{
			count++;
			cout<<"Object created:"<<count<<"\n";
		}
		~alpha()
		{
			cout<<"Object destroyed:"<<count<<"\n";
			count--;
		}
};
int main()
{
	alpha a1,a2,a3,a4;
	{
		alpha a5;
	}
	{
		alpha a6;
	}
	return 0;
}
