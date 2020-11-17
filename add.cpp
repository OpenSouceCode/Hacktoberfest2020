// CPP program to split array and move first 
// part to end. 
#include <bits/stdc++.h> 
using namespace std; 
  
void splitArr(int arr[], int n, int k) 
{ 
    for (int i = 0; i < k; i++) { 
  
        // Rotate array by 1. 
        int x = arr[0]; 
        for (int j = 0; j < n - 1; ++j) 
            arr[j] = arr[j + 1]; 
        arr[n - 1] = x; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 12, 10, 5, 6, 52, 36 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int position = 2; 
  
    splitArr(arr, 6, position); 
  
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 
