#include<iostream>
#include<map>
using namespace std;



int main()
{ 
    map <string,int> m1={                             // Declaration + Initialization
                          {"Rahul",90},
                          {"Aman",65},
                          {"Keshav",89},         // Here, Strings are the indexes(key) and numerics are the values(its values)
                          {"Armaan",60},         // KEY & VALUE pair.
                          {"Ayush",80}            
                       };


/* -------IMP ---  If numerics are the indexes, then they will be stored in ascending order as index no. whereas the strings will be as in 
                   dictionary order.  */                      

/* We can't change the indexes(no. or any string) whereas we can change the values of the values. of it.. 

/* m1["Rahul"]=89;
   m1["Aman"]=65;
   m1["Keshav"]=89;               // Initialization(another way) 
   m1["Armaan"]=60;
   m1["Ayush"]=80;
 */

/* m1.at("Rahul")=89;
   m1.at("Aman")=65;
   m1.at("Keshav")=89;               // Initialization(using at() function) 
   m1.at("Armaan")=60;
   m1.at("Ayush")=80;
 */
  

  cout<<m1["Keshav"]<<"\n\n";
  cout<<m1["Ayush"]<<"\n\n";
  cout<<m1["Rahu"]<<"\n\n";         // If you write an index(key) to print its value in the printing function which is NOT PRESENT in the whole associative array, then the program will  
                                    // make an index of it (of user-entered name or no.) and will store 0 (as null value) in it.

  for (auto v : m1)                // Here v is NOT a pointer or iterator.
 cout<<v.second<<endl;
  
  cout<<"\n";
  map <string,int>::iterator p=m1.begin();               //Iterative(pointer) method
   
  while (p!=m1.end())
  {
      cout<<p->first<<endl;
      p++;
  } 

  cout<<"\n";

  cout<<m1.size();        // will return the size (No. of pairs)
  
  cout<<"\n";

  cout<<m1.empty();     // checks if the array is empty or not, if it is .. it will return 1 otherwise 0;
  
  cout<<"\n\n";

  // m1.clear()        Will clear all data.

  m1.insert(pair<string,int>("Naman",70));
 
  for (auto x : m1)
  cout<<x.first<<endl;

  cout<<"\n";

  cout << distance(m1.begin(),m1.find("60"));





}