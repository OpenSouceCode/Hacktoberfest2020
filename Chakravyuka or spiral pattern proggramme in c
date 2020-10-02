#include<stdio.h>
main()
{
 int i,j,a[100][100],size,row=0,col=0,boundaryStart=0,boundaryEnd,num,evenRowCol=0,evenRow=0,evenCol=0,count=1;
 printf("Enter number of rows\n");
 scanf("%d",&size);
 boundaryEnd=size-1;
 for(i=0;i<size;i++) 
{
 for(j=0;j<size;j++) a[i][j]=0;
 
}
 while(count<=(size*size)) 
{
 if(evenRowCol%2==0) 
{
 if(evenRow%2==0) 
{
 for(i=col;(i<=boundaryEnd) && (count<=size*size);i++)
{
 a[row][i]=count;
 count++;
 
}
 evenRow++;
 col=i-1;
 row++;
 
}
 else 
{
 for(i=col;(i>=boundaryStart) && (count<=size*size);i--) 
{
 a[row][i]=count;
 count++;
 
}
 evenRow++;
 col=i+1;
 row--;
 boundaryStart++;
 
}
 evenRowCol++;
 
}
 else 
{
 if(evenCol%2==0) 
{
 for(i=row;(i<=boundaryEnd) && (count<=size*size);i++) 
{
 a[i][col]=count;
 count++;
 
}
 row=i-1;
 col--;
 evenCol++;
 
}
 else 
{
 for(i=row;(i>=boundaryStart) && (count<=size*size);i--) 
{
 a[i][col]=count;
 count++;
 
}
 row=i+1;
 col++;
 evenCol++;
 boundaryEnd--;
 
}
 evenRowCol++;
 
}
 
}
 for(i=0;i<size;i++) 
{
 for(j=0;j<size;j++) printf("%3d ",a[i][j]);
 printf("\n");
 
}

}
 

