#include <stdio.h>
int main()
{
    int nth;
   printf("Enter n to compute the nth prime number: ");
   scanf("%d", &nth);
    int num, count, i;
    num=1;
    count=0;
    while (count < nth){
      num=num+1;
      for (i = 2; i <= num; i++){
        if (num % i == 0) {
          break;
        }
      }
      if ( i == num){
        count = count+1;
      }
    }
    printf("Value of nth prime: %d",num);
  }
