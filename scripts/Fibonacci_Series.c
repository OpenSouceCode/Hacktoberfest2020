#include<stdio.h>

void fibonacci(int n){

    int n1 =0, n2=1, i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", n1);
        int next= n1+n2;
        n1=n2;
        n2=next;
    }
}


int main() {
   
    int n;
    printf("Enter the no of element in series:");
    scanf("%d",&n);

    fibonacci(n);

    return 0;
}
