#include <stdio.h>

int main()
{
   int n,;
    int count=0;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    cout<<"enter array elements";
    for(int i=0;i<n;i++ ){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
          if(arr[i]>arr[j])
              {
                 int temp=arr[j];
                      arr[j]=arr[i];
                      arr[i]=temp;
              }      
       }
    
    }
    cout<<"largest element is"<<arr[n-1];
     cout<<"smallest element is"<<arr[0];
   
  return 0;
}
