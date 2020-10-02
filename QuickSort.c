#include<stdio.h>

void QuickSort(int array[],int start,int end);

main()

{

 int i,j,array[100],num;

 printf("Enter Number of Elements in Array\n");

 scanf("%d",&num);

 printf("Enter Elements of Array\n");

 for(i=0;i<num;i++)

 scanf("%d",&array[i]);

 QuickSort(array,0,num);

 printf("Array after Sorting\n");

 for(i=0;i<num;i++)

 printf("%d ",array[i]);

 printf("\n");

}

void QuickSort(int array[],int start,int end)

{

 int index=start,i,pivot=array[end],temp;//taking the last number in array as pivot

 if(start<end)

 {

  for(i=start;i<end;i++)

  {

   if(array[i]<=pivot)//swapping index element and element at ith position if ith element is lesser than pivot element

   {

    temp=array[i];

    array[i]=array[index];

    array[index]=temp;

    index++;

   }

  }

  //finally after this loop we will get the position to interchange the pivot with index so that all the

  //elements greater than pivot wil be right side and lesser than pivot will be left side

  temp=array[index];

  array[index]=array[end];//we are taking  end element as pivot every time the quick sort function is called

  array[end]=temp;

  QuickSort(array,start,index-1);

     QuickSort(array,index+1,end);

 }

}

OUTPUT :
Enter Number of Elements in Array

5

Enter Elements of Array

35

30

45

12

90

Array after Sorting

12 30 35 45 90



