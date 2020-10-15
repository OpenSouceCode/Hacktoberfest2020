//Problem: Find y(1.4) using RK Method of 0rder 4, given (dy/dx)=x^2+y^2*x, y(1)=0, taking h=0.1

#include <stdio.h>
#include <stdlib.h>


//Defining the dy/dx function
float func(float x, float y){
	return (x*x + y*y*x);
}


void main(){
	float x0,y0,h,y,z,i,n,k1,k2,k3,k4,k;
	printf("Implementation of RK Method of Order 4\n\n");
	printf("Enter the values of x0,y0,h,z:\n");
	scanf("%f %f %f %f",&x0,&y0,&h,&z);
	n = (int)((z-x0)/h);
	
	//Implementing the RK Method of order 4
	for(i=1;i<=n;i++){
		k1 = h*func(x0,y0);
		k2 = h*func(x0+ h*.5, y0+ k1*.5);
		k3 = h*func(x0+ h*.5, y0+ k2*.5);
		k4 = h*func(x0+h, y0+k3);
		k = (k1+2*k2+2*k3+k4)/6.0;
		y0 = y0+k;
		x0 = x0+h;
	}
	
	printf("\ny0: %f",y0);
	getch();
}

/*
Input:

x0 = 1
yo = 0
h = 0.1
z = 1.4

Output:

yo: 0.417114
*/




