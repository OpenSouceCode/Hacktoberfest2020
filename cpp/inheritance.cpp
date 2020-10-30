#include<iostream>
using namespace std;
class student
{
	int roll;
	public:
		void getroll()
		{
			cout<<"enter roll no.";
			cin>>roll;
		}
		void putroll()
		{
				cout<<roll;
			
		}
	
};
class marks:public student
{
	protected:
		float s1,s2;
		public:
			void getmarks()
			{ cout<<"enter the marks of subject 1 \n";
				cin>>s1;
				cout<<"eneter the marks of subject 2";
				cin>>s2;
			}
			void putmarks()
			{
				cout<<s1<<"\n"<<s2<<"\n";
			}
 } ;
 class sports
 {
 	protected:
 		int score;
 		public:
 			void getscore()
 			{ cout<<"enter the score";
 			
 				cin>>score;
			 }
			 void putscore()
			 {
			 	
			 	cout<<score<<"\n" ;
			 }
 };
 class result: public marks, public sports
 {
 	float total;
 	public:
 		void display()
 		{ putroll();
 		putmarks();
 		putscore();
 		total=s1+s2+score;
 		cout<<"\n"<<total;
		 }
 };
 int main()
 {
 	result r;
 	r.getroll();
 	r.getmarks();
 	r.getscore();
 	r.display();
 return 0;	
 }

