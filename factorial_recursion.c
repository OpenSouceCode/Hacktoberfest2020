#include <stdio.h> 

int factorial(int num) {

  if(num <= 1) {
    return 1;
  }
  
  return num * factorial(num-1);
}

int main() { 
  
  int num, result;
  printf("Insert the number: ");
  scanf("%d", &num);
  result = factorial(num);
  printf("Result = %d", result);
	return 0; 
}
