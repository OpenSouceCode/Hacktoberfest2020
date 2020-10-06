#include<iostream>
using namespace std;

void insertSort(int arr[], int n)
{
    for(int i=1;i<n;i++)        // going from left to right
    {
        int key = arr[i];       // assigning key or marker. starting from index val = 1
        int j = i-1;            // all elements on left of key are sorted and right are unsorted
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];  // swapping the array on either sides of key...
            j = j-1;            // till the position of key is ascertained in the ordered
        }
        arr[j+1] = key;         // placing key in the correct location
    }
}

int main()
{
    int n, arr[20];             
    cout << "Enter the size of the array \n";   
    cin >> n;
    cout << "Enter "<<n<<" no. of elements \n";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    insertSort(arr,n);
    cout << "The sorted array is \n";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}