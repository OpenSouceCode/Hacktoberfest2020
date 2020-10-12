#include <bits/stdc++.h>
using namespace std; 

int partition(int arr[], int low, int high) 
{ 
	int pivot = arr[low]; 
	int i = low - 1, j = high + 1; 

	while (true) { 
		do { 
			i++; 
		} while (arr[i] < pivot); 
		do { 
			j--; 
		} while (arr[j] > pivot); 
 
		if (i >= j) 
			return j; 

		swap(arr[i], arr[j]); 
	} 
} 


int part_ran(int arr[], int low, int high) 
{ 
	srand(time(NULL)); 
	int random = low + rand() % (high - low);  
	swap(arr[random], arr[low]); 

	return partition(arr, low, high); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 

		int pi = part_ran(arr, low, high); 

		quickSort(arr, low, pi); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout<<arr[i]<<" "; 

    cout<<endl; 
} 


int main() 
{ 
	int n;
    cin>>n;

    int arr[n];

    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 

	quickSort(arr, 0, n - 1); 

	cout<<"Sorted array: "<<endl; 
	printArray(arr, n); 
    
	return 0; 
} 
