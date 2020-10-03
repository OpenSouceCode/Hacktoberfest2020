public class MergeSort {
    void merge(int arr[], int l, int m, int r)
    {
        //Find the sizes of the subarrays to be merged.
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays*/
        int L[] = new int[n1];
        int R[] = new int[n2];


        /*Copy the data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        /* Merge the temp arrays*/


        // Initial values of first and second subarrays.
        int i = 0, j = 0;

        //Initial index of merged subarray
        int k = l;
        //Merging tha arrays
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /*Copy the remaining elements of L[] if any*/
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        /*Copy remaining elements of R[] if any*/
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }


    void sort(int arr[], int l, int r)
    {
        if (l < r) {
            //Find the middle point.
            int m = (l + r) / 2;

            //Sort first and second half.
            sort(arr, l, m);
            sort(arr, m + 1, r);

            //Merge the sorted halves
            merge(arr, l, m, r);
        }
    }


    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }


    public static void main(String[] args) {
        int arr[] = { 493,227,349,24,157,111,326,69,56,104,92,60,144,211,342,643,23,115,22 }; //Just a random array

        System.out.println("Given Array");
        printArray(arr);

        MergeSort ob = new MergeSort();
        ob.sort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array");
        printArray(arr);

    }

}
