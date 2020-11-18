#include <iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    // vector<int> v(5);
    vector<int> v;
    vector<int>::iterator it1;
    for(int i=0;i<5;i++)
    {
        v.push_back((i+1)*(i+1));  /// WHen Size is Not declared
        // v[i]=i+1;
    }
    for(it1=v.begin();it1!=v.end();it1++)
    cout<<*it1<<endl;
//   cout << "Hello World" << endl; 

    string  st="Ashutosh";
    string s1(st,3,7);
    cout<<st<<endl;
    cout<<s1<<endl;
    string s2=st.substr(2,4);
    cout<<s2<<endl;
    if(s1.compare(s2)==0)
    cout<<" Equal"<<endl;
    else
    cout<<"Not Equal"<<endl;
    
    pair<int,char> p;
    p=make_pair(1 ,'4');
    pair<int, char> p2(1,'a');
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    
    set<int> s;
    int arr[] ={1,2,3,4,5,6,7,8,9,0,1,2,3};
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
  s.insert(arr[i]);
  set<int> ::iterator its;
  for(its=s.begin();its!=s.end();its++)
  cout<<*its<<" ";
   
   
  if(s.find(800/100)==s.end())
  cout<<"Not Found"<<endl;
  else
  cout<<"Found"<<endl;


    int arr2[]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5};
    map<int,int> m;
    for(int i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
    m[arr2[i]]+=1;
    map<int,int>::iterator it3;
    for(it3=m.begin();it3!=m.end();it3++)
    cout<<it3->first<<" : "<<it3->second<<endl;
    
    cout<<endl;
    m.erase(5);
    
    for(it3=m.begin();it3!=m.end();it3++)
    cout<<it3->first<<" : "<<it3->second<<endl;
    cout<<endl;
    
    int arr3[]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5};
    unordered_map<int,int> m1;
    for(int i=0;i<sizeof(arr3)/sizeof(arr3[0]);i++)
    m1[arr3[i]]+=1;
    unordered_map<int,int>::iterator it2;
    for(it2=m1.begin();it2!=m1.end();it2++)
    cout<<it2->first<<" : "<<it2->second<<endl;
    
    cout<<endl;
    m.erase(5);
    
    for(it2=m1.begin();it2!=m1.end();it2++)
    cout<<it2->first<<" : "<<it2->second<<endl;
    cout<<endl;
    
    
   return 0;
}