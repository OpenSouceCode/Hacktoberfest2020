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
    int min = minimum(A, size);
    // printf("%d\n",min);
    int max = maximum(A, size);
    // printf("%d\n",max);
    int sum = min + max;
    printf("%d",sum);
    return 0;
}