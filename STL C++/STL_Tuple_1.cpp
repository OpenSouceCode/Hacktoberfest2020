#include<iostream>
#include<tuple>                      //Header file ...
using namespace std;




int main()
{
    string str="Hello World";
    int ab=619;

    tuple <string,int,int> t1;            //Declaration 
    tuple <string,int,int> t2("Manav Naharwal",76,99);        //Declaration + initialization
    tuple <string&,int&> t3(str,ab);                  //  We can also store references. (NOT ADRESSES)

    t1=make_tuple("Rahul",15,30);             // Initialization              



                                         // To Print the values of a tuple object, we use get <Position No.> (Object); 
     cout<<get<0>(t1)<<endl;
     cout<<get<1>(t1)<<endl;
     cout<<get<2>(t1)<<endl;

     cout<<"\n";

     cout<<get<0>(t2)<<endl;
     cout<<get<1>(t2)<<endl;
     cout<<get<2>(t2)<<endl;
 
     cout<<"\n";

     cout<<get<0>(t3)<<endl;
     cout<<get<1>(t3)<<endl;



                        
}
