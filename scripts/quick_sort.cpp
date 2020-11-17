#include <iostream>

using namespace std;
void quick_sort(int, int, int);
int partition(int *, int, int);

void quick_sort(int *A, int start, int end)
{
    if (start < end)
    {
        int p_index = partition(A, start, end);
        quick_sort(A, start, p_index - 1);
        quick_sort(A, p_index + 1, end);
    }
}

int partition(int *A, int start, int end)
{
    int pivot = A[end];
    int p_index = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(A[i], A[p_index]);
            p_index++;
        }
    }
    swap(A[p_index], A[end]);
    return p_index;
}
int main()
{
    int n;
    cout << "Enter the number of elements in an array : ";
    cin >> n;
    int A[n];
    cout << "Enter the number of elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Entered Array is : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    quick_sort(A, 0, n - 1);
    cout << endl;
    cout << "The sorted array is : ";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
