#include <stdio.h>

int maximum(int A[], int n){
    int mx = A[0];
    for (int i = 1; i < n; i++)
    {
        if(mx < A[i]){
            mx = A[i];
        }
    }
    return mx;
    
}
int minimum(int A[], int n){
    int mn = A[0];
    for (int i = 1; i < n; i++)
    {
        if(mn > A[i]){
            mn = A[i];
        }
    }
    return mn;
    
}

int main(){
    int A[] = {1, 3, 4, 1}; 
    int size = (sizeof(A)/sizeof(int));
    //printing the sum
    printf("%d",minimum(A, size) + maximum(A, size) );
    return 0;
}
