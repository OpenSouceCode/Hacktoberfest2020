Like Merge Sort, QuickSort is a Divide and Conquer algorithm. 
It selects an object as a pivot and separates the given list around the selected pivot. There are many different types of quickSort that choose pivot in different ways.

Always choose the first item as a pivot.
Always select the last item as pivot (used below)
Choose a random item as a pivot.
Select medium as pivot.
Key process in quickSort split ().
A Target of partitions is given, array and element x of array as pivot, insert ix in its proper place in the order of order and place all smaller objects (smaller than x)
before x, and then place all larger objects (larger than x) behind x. All of this should be done at the right time.


#include<stdio.h>
void quicksortprogram(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksortprogram(number,first,j-1);
      quicksortprogram(number,j+1,last);

   }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksortprogram(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
