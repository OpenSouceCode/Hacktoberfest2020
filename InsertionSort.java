


import java.util.Arrays;

public class InsertionSort {
    public static int[] insertionSortAscending(int[] arr1){
       int arr[] =arr1.clone();
       int i = 1;
       while(i<arr.length){

           int currentMax = arr[i];
           int j = i-1;

           while (j>=0 && arr[j]>currentMax){

               arr[j+1] =arr[j];
               j--;
           }
           arr[j+1] =currentMax;
           i++;
       }

       return arr;
    }
    public static int[] insertionSortDescending(int[] arr1){
        int arr[] =arr1.clone();
        int i = 1;
        while(i<arr.length){

            int currentMax = arr[i];
            int j = i-1;

            while (j>=0 && arr[j]<currentMax){

                arr[j+1] =arr[j];
                j--;
            }
            arr[j+1] =currentMax;
            i++;
        }

        return arr;
    }
    public static int[] insertionSort(int[]arr){
        int i = arr.length-2;
        while (i>=0){
            int current =arr[i];
            int j= i+1;
            while (j<arr.length && arr[j]>current){
                arr[j-1] =arr[j];
                j++;
            }
            arr[j-1] =current;
            i--;
        }
        return arr;
    }

    public static void main(String[] args) {
        int arr [] = {64,7,87,413,1,1,484,513,546,3,3,4,889798,41,654,6};


        System.out.println(Arrays.toString(insertionSortAscending(arr)));
        System.out.println(Arrays.toString(insertionSortDescending(arr)));
        System.out.println(Arrays.toString(insertionSort(arr)));

    }
}
