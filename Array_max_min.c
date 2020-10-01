#include <stdio.h>
struct min_max
{
    int mn;
    int mx;
};
struct min_max findmnmx(int A[], int n)
{
    struct min_max mnmx;
    int i;
    if(n%2 == 0)
    {
        if (A[0] > A[1])
        {
            mnmx.mx = A[0];
            mnmx.mn = A[1];
        }
        else
        {
            mnmx.mn = A[0];
            mnmx.mx = A[1];
        }
        i = 2;
    }
    else
    {
        mnmx.mn = mnmx.mx = A[0];
        i = 1;
    }
    while(i < n-1)
    {
        if(A[i] > A[i+1])
        {
            if(A[i]>mnmx.mx)
                mnmx.mx = A[i];
            if(A[i+1]<mnmx.mn)
                mnmx.mn = A[i+1];
        }
        else
        {
            if(A[i+1] > mnmx.mx)
                mnmx.mx = A[i+1];
            if(A[i] < mnmx.mn)
                mnmx.mn = A[i];
        }
        i+=2;
    }
    return mnmx;
}

int main(){
    int A[] = {1, 3, 4, 1}; 
    int size = (sizeof(A)/sizeof(int));
    struct min_max mnmx = findmnmx(A, size);
    //printing the sum of max and min elements
    printf("%d",mnmx.mn + mnmx.mx );
    return 0;
}
