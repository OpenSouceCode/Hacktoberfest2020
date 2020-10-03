#include<iostream>
using namespace std;
int main(){
int i,m,temp;
cout<<"Enter the length of array";
cin>>m;
int arr[m];
for (i=0;i<m;i++){
    cout<<"Enter the "<<i+1<<" th element";
    cin>>arr[i];
}
int low=0,high=m-1;
while (low<=high){
    temp=arr[low];
    arr[low]=arr[high];
    arr[high]=temp;
    low++;
    high--;
}
for (i=0;i<m;i++){
    cout<<"The "<<i+1<<" element is:"<<arr[i]<<endl;
}
return 0;
system("pause");
}
