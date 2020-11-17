#include<graphics.h>
#include<stdio.h>
#include<math.h>
void main()
{
int driver=DETECT,mode,j=100,i=0,x1,x22,x2,x11,y1,y11,y2,y22,a,y,k,speed;
float ang1=3.839724354,ang2=5.585053606, c1=0.05,
c2=-0.05,var1=2.967059728,var2=5.410520681,d1=0.072,d2=-0.072,s=2.35619449
;
initgraph(&driver,&mode,"C:\tc\bgi");
printf("

 Enter the number of rounds
"); scanf("%d",&k);printf("
Enter 1 for fast speed or 2 for normal speed
");scanf("%d",&speed);
if(speed==1) speed=11; else speed=16;cleardevice();delay(1000);
while(k>=1)
{
 while(i<=700)
 {setcolor(8);
 circle(i,j,22);line(i,j+22,i-13,j+115);
 x1=i+50*cos(ang1);x2=i+50*cos(ang2);
 y1=j+22-50*sin(ang1);y2=j+22-50*sin(ang2);
 x11=x1+45*cos(ang1+1.54532952); x22=x2+45*cos(ang2+1.54532952);
 y11=y1-45*sin(ang1+1.54532952);
y22=y2-45*sin(ang2+1.54532952);setcolor(RED);

line(i,j+22,x1,y1);line(x1,y1,x11,y11);setcolor(GREEN);line(i,j+22,x2,y2);
line(x2,y2,x22,y22);
 x1=i-15+60*cos(ang1);  x2=i-15+60*cos(ang2);
 y1=j+115-60*sin(ang1); y2=j+115-60*sin(ang2);
 x11=x1+60*cos(var1); x22=x2+60*cos(var2);
 y11=y1-60*sin(var1); y22=y2-60*sin(var2);

line(i-13,j+115,x1,y1);line(x1,y1,x11,y11);setcolor(RED);line(i-13,j+115,x
2,y2);line(x2,y2,x22,y22);
 ang1=ang1+c1; ang2=ang2+c2;
 var1=var1+d1; var2=var2+d2;if(i==0) a=x22;
 if(ang1<=3.839724354){c1=0.05;var1=2.967059728;d1=0.072;}

if(ang1>=5.585053606){c1=-0.05;var1=5.410520681;d1=-0.072;a=x11+10;s=2.356
19449;}
 if(ang2<=3.839724354){c2=0.05;var2=2.967059728;d2=0.072;}
 if(ang2>=5.585053606){
c2=-0.05;var2=5.410520681;d2=-0.072;a=x22+10;s=2.35619449;}
 i=a+150*cos(s)+50;j=320-150*sin(s)-20;s=s-0.045;
 delay(speed);if(k!=1)cleardevice();
 }
 i=0;k--;
 }
getch(); }
