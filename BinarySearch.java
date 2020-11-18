//Binary Search Implementation
import java.util.Scanner;

public class BinarySearch{
	//Returns the index of the searched item in the array. If not, returns -1.
	public int search(int arr[],int item) {
		int N = arr.length;
		int lo=0,hi=N-1;
		while(lo<=hi) {
			int mid = lo + (hi-lo)/2;
			if(arr[mid] == item) {
				return mid;
			}
			else if(item > arr[mid]) {
				lo = mid+1;
			}
			else if(item < arr[mid]) {
				hi = mid-1;
			}
		}
		return -1;	
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BinarySearch bs = new BinarySearch();
		int[] arr = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38};
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i] + "\t");
		}
		System.out.print("Enter the item you want to search: ");
		int item = sc.nextInt();
		int result = bs.search(arr, item); 
		if(result==-1) {
			System.out.println("The item is not present in the array!");
		}
		else System.out.println("The item is found at index "  +result);
	}
}

