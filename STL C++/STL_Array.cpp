#include<iostream>
#include<array>
using namespace std;

int main()
{
    array <int,6> obj1={34,12,11,56,41,37};           // First value in angular brackets will be a datatype and second will be a size. 
    array <int,6> obj2={1,2,3,4,5,6};
    array <int,9> obj3={1,2,3,4,5,6};           

    cout<<obj1.at(1)<<endl;                    // will return the value at the given address
    cout<<obj1[1]<<endl;                    
    
    cout<<obj1.front()<<endl;                  // will always return the first value of the array. 
    cout<<obj1.back()<<endl;                  // will always return the last value of the array.

    obj1.fill(10);                         // will store value 10 at ALL INDEXES..
    cout<<endl;

    for(int i=0;i<6;i++)
    cout<<obj1.at(i)<<endl;

    cout<<"\n";

    obj1.swap(obj2);                    // will swap the values between the two arrays....
                                            /* CONDITION  Both arrays should have same size and datatype. */
      for(int i=0;i<6;i++)
    cout<<obj1.at(i)<<endl;

     cout<<"\n\n";

      for(int i=0;i<6;i++)
    cout<<obj2.at(i)<<endl;

     cout<<"\n\n";
     
     cout<<obj3.size();    // will return the size(declared one) of the array.

     

    