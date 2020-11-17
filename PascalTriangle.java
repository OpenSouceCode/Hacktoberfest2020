
import java.util.*;
public class PascalTriangle {
	
		static int facto(int n) {
			int factorial;

			for(factorial = 1; n > 1; n--){
				factorial *= n;
			}
			return factorial;
		    }
		    static int ncr(int n,int r) {
			return facto(n) / ( facto(n-r) * facto(r) );
		    }
		    public static void main(String args[]){
			int rows, i, j;

			//getting number of rows from user
			System.out.println("N:");
			Scanner scanner = new Scanner(System.in);
			rows = scanner.nextInt();
			scanner.close();
            if(rows>10) {
            	System.out.println("Invalid number of rows(rows<=10)");
            return;
            }
            else {
			System.out.println("Pascal Triangle:");
			for(i = 0; i < rows; i++) {
				for(j = 0; j < rows-i; j++){
					System.out.print(" ");
				}
				for(j = 0; j <= i; j++){
					System.out.print(" "+ncr(i, j));
				}
				System.out.println();
		 	}}
		    }
	

}
