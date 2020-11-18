#include<iostream>
using namespace std;
int main()
{
    
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    cout<<"enter elements in array";
    int i,j,s;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for( i=0;i<n;i++)
    {  s=-1;
       for(j=i+1;j<n;j++)
       {
         if(arr[j]>arr[i])
         {
             s=arr[j];
             break;
         }
       }
    }
    cout<<arr[i]<<" ";
    cout<<s<<" ";
}

