
import java.util.*;
public class selection_sort {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Number of elements in the array:");
		int n=sc.nextInt();
int a[]=new int[n];
 
	System.out.println("Enter elements:");
	for(int i=0;i<n;i++)
		a[i]=sc.nextInt();
	for(int i=0;i<n-1;i++) {
		int m=i;
		for(int j=i+1;j<n;j++) {
			if(a[j]<a[m])
				m=j;
		}
		
			int t=a[i];
			a[i]=a[m];
			a[m]=t;
		
	}
	System.out.println("The sorted array is:");
	for(int i=0;i<n;i++)
		System.out.println(a[i]);
}
}
