#include <stdio.h>
#include<conio.h>
//Use console input output header file (conio.h) for using predefined functions clrscr()(for clearing the output screen) and getch()(for getting a character for terminating the output screen)

int maximum(int A[], int n){
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
    
}
int minimum(int A[], int n){
    int min = A[0];
    for (int i = 1; i < n; i++)
    {
        if(min > A[i]){
            min = A[i];
        }
    }
    return min;
    
}

void main(){
    clrscr();  //for clearing the console screen
    int A[] = {1, 3, 4, 1}; 
    int size = (sizeof(A)/sizeof(int));
    int min = minimum(A, size);
    // printf("%d\n",min);
    int max = maximum(A, size);
    // printf("%d\n",max);
    int sum = min + max;
    printf("%d",sum);
    getch(); //for getting a character
}
