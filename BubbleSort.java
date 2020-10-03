public class BubbleSort {

    public static void bubbleSort(int[] arr)
    {
        int n = arr.length;
        int flag = 0;
        for(int i=0;i<n-1;i++)
        {	flag = 0;
            for(int j = 0; j<n-i-1; j++) //Since the sorting in Bubble sort  takes place from the end,so that's why (n-i-1).
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag=1;
                }
            }
            if(flag==0) break;	  //This exits the loop if the swap statement in inner j loop doesn't execute, it means the array is sorted.
        }
    }

    static void printArray(int arr[])
    {
        int n = arr.length;

        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
    }




    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Before Sorted Array");
        printArray(arr);

        bubbleSort(arr);

        System.out.println("Sorted Array");
        printArray(arr);
    }

}

