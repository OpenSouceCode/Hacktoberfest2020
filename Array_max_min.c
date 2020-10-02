#include <stdio.h>

int maximum(int A[], int n){
    int mx = A[0]; //declared mx as first element in the array making it as maximum element in the array
    for (int i = 1; i < n; i++)
    {
        if(mx < A[i]){ //checking if mx is lesser than present element in the array
            mx = A[i]; //updating the value of mx to maximum element in the array
        }
    }
    return mx; //returning the max element in the array
    
}
int minimum(int A[], int n){
    int mn = A[0]; //declared mn as first element in the array making it as minimum element in the array
    for (int i = 1; i < n; i++)
    {
        if(mn > A[i]){ //checking if mn is greater than present element in the array
            mn = A[i]; //updating the value of mn to minimum element in array
        }
    }
    return mn; //returning the min element in the array
    
}

int main(){
    int A[] = {1, 3, 4, 1};  //declared and initialized the array A
    int size = (sizeof(A)/sizeof(int)); 
    //printing the sum
    printf("%d",minimum(A, size) + maximum(A, size) ); //printing the sum of greatest and smallest element in the array
    return 0;
}
