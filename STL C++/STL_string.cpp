#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    s1="Hello ";               // Implicit copy assignment operator.
    string s2 = "Students";
    char str[]=" Ice Age";

    string s3;

    s3=s1+s2;                
    cout<<s1<<endl<<s2<<endl<<s3;
    cout<<"\n\n";
    
    string s4;
    cout<<"Enter your Name : ";
    getline(cin,s4);                     //--------------------

    cout<<s4;
    cout<<"\n\n";

   /*------------------------------------------Mixed Operations----------------------------------------*/

    string s5;
    s5=s1+str;                               // Concatenation of a string object s1 and a char array str can be done.
    
    s5=s1 + " Fire";                          // Concatenation of a string object s1 and a direct string is possible.
    // s5=s1 + Fire;   //Wrong (Fire is not a string here)
 
    s5 = s1+ 'A';                            //Possible

    cout<<s5<<"\n\n";


    
    















    return 0;

}