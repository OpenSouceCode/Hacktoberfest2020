
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class HeapSort {
    public void heapify(int[] arr, int n, int i){
        int largest =i;
        int l = 2*i+1;
        int r = 2*i+2;

        if(l<n && arr[largest]<arr[l]){
            largest = l;

        }
        if(r<n && arr[largest]<arr[r]){
            largest = r;
        }
        if(largest !=i){
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr,n,largest);
        }
    }
    public  void heapSort(int[] arr){
        int n = arr.length;
        for (int i = 0;i<arr.length;i++){
            heapify(arr,n,i);
        }
        for (int k = n-1;k>0;k--){
            int temp = arr[0];
            arr[0] = arr[k];
            arr[k] = temp;
            heapify(arr, k, 0);
        }
    }
    public static void main(String[] args) {
        Random rd = new Random();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the array ");
        int len = sc.nextInt();
        System.out.println(len);
        int arr[] = new int[len];
        int i=0;
        while (i<len){
            arr[i] = rd.nextInt();
            System.out.println(arr[i]);
            i++;
        }
        HeapSort ob = new HeapSort();
        ob.heapSort(arr);
        System.out.println(Arrays.toString(arr));

    }
}
