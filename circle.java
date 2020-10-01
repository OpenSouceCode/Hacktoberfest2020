import java.util.Scanner;
class Circle
{
	public static void main(String arg[]){
		Scanner KB=new Scanner(System.in);
		System.out.println("Enter the radius of circle:");
		int r=KB.nextInt();
		int d=2*r;
		int a=(22/7)*r*r;
		int c=(22/7)*2*r;
		System.out.println("Diameter of the circle is="+d);
		System.out.println("Area of the circle is="+a);
		System.out.println("Perimeter of the circle is="+c);
	}
}
