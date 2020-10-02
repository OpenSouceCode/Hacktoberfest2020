#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int start, int mid,int mid2, int end)
{
	int size1 = mid2 - start; 
    int size2 = end - mid; 
  
    int arr1[size1], arr2[size2]; 
  
    for (int i = 0; i < size1; i++) 
        arr1[i] = arr[start + i]; 
    for (int j = 0; j < size2; j++) 
        arr2[j] = arr[mid2 + j]; 
  	int i = 0; 
    int j = 0; 
    int k = start;
    while (i < size1 && j < size2) { 
        if (arr1[i] <= arr2[j]) { 
            arr[k] = arr1[i]; 
            i++; 
        } 
        else { 
            arr[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < size1) { 
        arr[k] = arr1[i]; 
        i++; 
        k++; 
	} 
  
    while (j < size2) { 
        arr[k] = arr2[j]; 
        j++; 
        k++; 
    } 
}
int mergesort(int arr[], int start, int end)
{
	if(start == end)
		return arr[start];
	
	else
	{
		int mid = (start + end )/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid, mid+1 , end);
	}
}
int main()
{
	int arr[5] = { 1, 4, 5, 3, 2};
	cout<<"The array before sorting is: ";
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	cout<<"The array after sorting is: ";
	mergesort(arr,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
