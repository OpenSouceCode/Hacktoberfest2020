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
    int size;
    printf(""Enter the no of elements you will enter\n");
    scanf("%d",&size);
    int A[size];
    printf("Enter the elements\n");
    for(int i=0;i<size;i++)
           scanf("%d",&A[i]);
    //printing the sum
    printf("Sum is: %d",minimum(A, size) + maximum(A, size) );
    return 0;
}
