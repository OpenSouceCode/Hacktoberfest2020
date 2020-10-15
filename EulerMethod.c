//Problem: Using Euler method determine y(0.6), given dy/dx = x-y with y(0) = 1, taking h=0.2

#include <stdio.h>
#include <stdlib.h>

//Defining the function
float func(float x,float y){
    return x-y;
}

void main(){
	float x0,y0,h,z,i,n;
	printf("Implementation of Euler Method\n\n");
	printf("Enter the values of x0,y0,h,z:\n");
	scanf("%f %f %f %f",&x0,&y0,&h,&z);
	n = (int)((z-x0)/h);


	//Implementing the Euler Method
	for(i=0;i<=n;i++){
		y0 = y0 + h*func(x0,y0);
		x0 = x0 + h;
	}

	printf("\ny0: %f",y0);
	getch();
}

/*
Input:

x0 = 0
y0 = 1
h = 0.2
z = 0.6

Output:

y0 = 0.619200
*/
