#include <stdio.h>
void insert(int*,int);
void delet(int*,int);
int main(void) {
  int heap[] ={10,20,30,25,5,40,35};
  int n = 7;
  for(int i= 1;i<7;i++)
  {
    insert(&heap[0],i);
  }
  printf("\n");
  delet( &heap[0], n);
  delet( &heap[0], n-1);
  delet( &heap[0], n-2);
  delet( &heap[0], n-3);
  delet( &heap[0], n-4);
  delet( &heap[0], n-5);
  for(int i=0;i<7;i++)
  {
    printf("%d ",heap[i]);
  }
  return 0;
}
void insert(int * heap,int i)
{
  while(i>0)
  {
    if(heap[i]>heap[(i-1)/2])
  {
    int temp = heap[i];
    heap[i]= heap[(i-1)/2];
    heap[(i-1)/2]= temp;
  }
    i = (i-1)/2;
  }
}
void delet(int *heap,int n)
{
  int i,j,val;
  val = heap[0];
  heap[0]= heap[n-1];
  heap[n-1]=val;
  i =0,j = 2*i +1;
  
  while(j<n-2)
  {
    if(heap[j]<heap[j+1]){
      j = j+1;
    }
    if(heap[i]<heap[j])
    {
      int temp = heap[i];
      heap[i] = heap[j];
      heap[j] = temp;
      i = j;
      j = 2*j+1;
    }
    else
    break;
    
  } 
}