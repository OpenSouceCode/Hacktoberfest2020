#include <stdio.h> 

int fact(int num) {

  if(num <= 1) {
    return 1;
  }
  
  return num * fact(num-1);
}

int main() { 
  
  int num, result;
  printf("Insert the number: ");
  scanf("%d", &num);
  //result = fact(num);
  printf("Result = %d", fact(num));
	return 0; 
}
