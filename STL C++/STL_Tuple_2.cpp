#include<iostream>
#include<tuple>                      //Header file ...
using namespace std;

int main()
{
    char ch;
    int ab;
    float bc;

    typedef tuple <char,int,float> tp;

    tp t1('a',78,99.9);
    tp t2('b',68,21.869);
    tp t3;


    /* Tie Function */
    tie(ch,ab,bc)=t1;         // Transferring of data with help of tie function 
    t3=tie(ch,ab,bc);

    cout<<get<0>(t3)<<endl;
    cout<<get<1>(t3)<<endl;
    cout<<get<2>(t3)<<endl;
   
   cout<<"\n";

   tie(ch,ab,bc)=make_tuple('b',65,43.77);              
   t3=tie(ch,ab,bc);

    cout<<get<0>(t3)<<endl;
    cout<<get<1>(t3)<<endl;
    cout<<get<2>(t3)<<endl;
    
    cout<<"\n";

   cout<<tuple_size<tuple <char,int,float>>::value<<endl;              // Only type name is allowed    
                                                               // Prints the NO. OF ELEMENTS present in the tuple (here 3).
}
