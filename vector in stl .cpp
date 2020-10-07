//Vector

#include <bits/stdc++.h>
using namespace std;

void vector_Demo()
{
    vector<int>A = {11,32,65,65,100};

    A.push_back(132);
    A.push_back(100);
    A.push_back(100);
    

    vector<int>::iterator it1=A.begin();  // This is pointer
    //auto it=A.begin();  // This is another way of declaring iterator
   
    sort(A.begin(),A.end());
   
   // printing the vector
     for(it=A.begin();it!=A.end();it++)
     {
         cout<<*it<<" "<<endl;
     }
    
    cout<<endl;
  
  // Another way of Printing
     for(int x:A)
     {
         cout<<x<<endl;
     }

     bool present=binary_search(A.begin(),A.end(),65);//Only works on sorted array or vector O(nlogn)
     cout<<present<<endl;
     present=binary_search(A.begin(),A.end(),1032);
     cout<<present<<endl;

    auto it3=lower_bound(A.begin(),A.end(),46); // >= greater than or equal to
    cout<<*it3<<endl;
    auto it4=upper_bound(A.begin(),A.end(),65); // > greater than
    cout<<*it4<<endl;

    cout<<it4-it3<<endl; //No of times 65 occur in vector

    
    auto it=find(A.begin(),A.end(),65);  // return the iterator pointing to 65 if not present then point to A.end() 

    cout<<it-A.begin()<<endl;
}


int main()
{
   vector_Demo();
  
    return 0;
}
