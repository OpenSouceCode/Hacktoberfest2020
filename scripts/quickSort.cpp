#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
// int partition(int arr[],int low, int high,int pivot)
// {
    // while(low<=high)
    // {
    //     while(arr[low]<pivot)
    //         low++;
    //     while(arr[high]>=pivot)
    //         high--;
    //     if(low<=high)
    //     {
    //         swap(&arr[low],&arr[high]);
    //         low++;
    //         high--;
    //     }

    // }
    // return low;
    
    int partition(int arr[],int low, int high)
    {
    int pivot = arr[high];
    int i = (low - 1)  ;// Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i + 1);
}

    

void sort(int arr[],int low, int high)
{
    if(low<high)
    {
        //int pivot = arr[(low+high)/2];
        int piv_index = partition(arr,low,high);
        sort(arr,low,piv_index-1);
        sort(arr,piv_index,high);
    }
}

int main()
{
    int n,arr[20];
    cout<<"Enter the size of array: ";
    cin >> n;
    cout << "\n Emter the element values \n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i]<<" ";

    return 0;
}