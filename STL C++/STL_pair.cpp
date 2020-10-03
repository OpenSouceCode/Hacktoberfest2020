#include<iostream>
using namespace std;                            // NO Header File required.

class student
{
    int age;
    string name;

    public:

    void setdata(string s,int a)
    {
        name=s;    age=a;
    }

    void showdata()
    {
        cout<<"\nName : "<<name;
        cout<<"\nAge : "<<age<<endl;
    }

};


int main()
{
    pair <int,float> p1(4,8.765);                 // Declaration methods for a pair 
    pair <string,string> p2;
    pair <string,float> p3;
    pair <int,student> p4;
    pair <int,int> p5(66,89);          // Declaration + initialization

                                     // Assigning values in pair(s) --- IN CASE OF PRIMITIVE DATATYPES  
    p2=make_pair("Rahul","Akshay");
    p3=make_pair("Hello World",6.433);

    student s1;
    s1.setdata("Aishwarya",25);         // For Class's objects, values must be initialized before making a pair. 

    p4=make_pair(87,s1);                     // For non-primitive datatype(s),an object must be passed which is already declared and initialized. 

    
    cout<<"\nPair 1"<<endl;                     // Printing the values.
    cout<<p1.first<<" "<<p1.second<<endl;         // .first will return the value of the first member of the pair, whereas .second will return 
                                                  //  the value of second member. 
    cout<<"\nPair 2"<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;

    cout<<"\nPair 3"<<endl;
    cout<<p3.first<<" "<<p3.second<<endl;

    cout<<"\nPair 4"<<endl;                        // ----------IMP------(Printing the value of a class object)
    cout<<p4.first;                      
                                               // We Can't directly print the values of an obkect by using just .second fn, instead first, we have 
    student s2 = p4.second ;                   // to store the values in an another object(say s2) which will be returned by the fn and then have to 
    s2.showdata();                                         // use user-created fn (say showdata) to print it. 

    cout<<p5.first<<" "<<p5.second<<endl;
 
 
                    // NOTE--- We can also do operator Overloading.
}