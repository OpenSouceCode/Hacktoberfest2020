#include <stdio.h>
int find(int A[], int n){ 
    int mx = A[0]; int mn = A[0]; 
    for (int i = 1; i < n; i++) { 
        if(mx < A[i]){
            mx = A[i]; } 
        if(mn > A[i]){ 
            mn = A[i]; } } 
    return (mx+mn); } 
int main(){ 
    int A[] = {1, 3, 4, 1}; 
    int size = (sizeof(A)/sizeof(int)); 
    printf("%d",find(A,size));
    return 0; 
}
