

import java.util.Arrays;

public class RadixSort {
    
    public static int getMax(int arr[]){
        int max = arr[0];
        for (int j = 1;j<arr.length;j++){
            if (arr[j]>max){
                max =arr[j];
            }
        }
        return max;
    }
    public static void countSort(int arr[],int exp){
        int output[] = new int[arr.length];
        int  i ;
        int count [] = new int[10];
        Arrays.fill(count,0);
        for (i= 0;i<arr.length;i++){
            count[(arr[i]/exp)%10]++;

        }
        for (i =1 ;i<10;i++){
            count[i] += count[i-1];
        }
        for (i = arr.length -1;i>=0;i--){
            output[count[(arr[i]/exp)%10]-1] =arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for (i = 0; i<arr.length;i++){
            arr[i] = output [i];

        }

    }
    public static void radixSort(int[] arr){
        int m = getMax(arr);
        for(int exp = 1 ; m/exp>0;exp*=10){
            countSort(arr,exp);
        }
    }
    public static void main(String[] args) {
        int arr[] ={
                46,87,3,12,35,48,41,3216,8498,413,2,3546,8513,2,354,64,12,687,5
        };
        radixSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
