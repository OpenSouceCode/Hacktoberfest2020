#include <iostream>
using namespace std;

void mergeSort(int[],int,int); 
void merge(int[],int,int,int);

//Display function to print values. 
void display(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}

int main() 
{
    int a[10]= {8, 4, 5, 1, 3, 9, 0, 2, 7, 6}; 
    int i; 
    
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Before sorting: \n"; 
    display(a, size);//Using display function to print unsorted array.
    cout<<"After sorting: \n";
    mergeSort(a,0,size-1); 
    display(a, size);//Using display function to print sorted array.
}
//Dividing the list into two sublist, sorting them and merging them.
void mergeSort(int a[], int strt, int end)
{
    int mid;
    if(strt<end)
    {
        mid = (strt+end)/2;
        
        mergeSort(a,strt,mid);//Divide
        mergeSort(a,mid+1,end);//Conqure
        merge(a,strt,mid,end);//Combine
    }
}
//Combining two sublist.
void merge(int a[], int strt, int mid, int end)
{
    int i=strt,j=mid+1,p,index = strt;
    int temp[10];
    
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[index] = a[i];
            i = i+1;
        }
        else
        {
            temp[index] = a[j];
            j = j+1;
        }
        
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = a[i];
            index++;
            i++;
        }
    }
    p = strt;
    while(p<index)
    {
        a[p]=temp[p];
        p++;
    }
}
