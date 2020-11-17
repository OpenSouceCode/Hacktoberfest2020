#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

check();
end();
win();
int m[500],n[500],con=20;
clock_t start,stop;
		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 		 void main(void)
{

int gd=DETECT,gm,ch,maxx,maxy,x=13,y=14,p,q,spd=100;

initgraph(&gd,&gm,"..\bgi");

setcolor(WHITE);
settextstyle(3,0,6);
outtextxy(200,2," SNAKE 2 ");
settextstyle(6,0,2);
outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
outtextxy(20,140," Avoid The Head Of Snake Not To Hit Any Part Of Snake
");
outtextxy(20,160," Pick The Beats Untill You Win The Game ");
outtextxy(20,200," Press 'Esc' Anytime To Exit ");
outtextxy(20,220," Press Any Key To Continue ");
ch=getch();
if(ch==27) exit(0);
cleardevice();
maxx=getmaxx();
maxy=getmaxy();

randomize();

p=random(maxx);
int temp=p%13;
p=p-temp;
q=random(maxy);
temp=q%14;
q=q-temp;



 start=clock();
int a=0,i=0,j,t;
while(1)
{

 setcolor(WHITE);
 setfillstyle(SOLID_FILL,con+5);
 circle(p,q,5);
 floodfill(p,q,WHITE);

   if( kbhit() )
   {
     ch=getch(); if(ch==0) ch=getch();
     if(ch==72&& a!=2) a=1;
     if(ch==80&& a!=1) a=2;
     if(ch==75&& a!=4) a=3;
     if(ch==77&& a!=3) a=4;
      }
       else
     {
     if(ch==27
     ) break;
     }

       if(i<20){
 		   m[i]=x;
 		   n[i]=y;
 		   i++;
	       }

		 if(i>=20)

		 {
	 		  for(j=con;j>=0;j--){
		 		  m[1+j]=m[j];
		 		  n[1+j]=n[j];
	 		 		  }
		   m[0]=x;
		   n[0]=y;

		   setcolor(WHITE);
		   setfillstyle(SOLID_FILL,con);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<con;j++){
		  setfillstyle(SOLID_FILL,con+j%3);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		 		      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);

		   }
     stop=clock();
     t=(stop-start)/CLK_TCK;
     printf(" TIME %d sec   ",t);
     printf("SCORE %d
",con-5);
     check();

    if(x==p&&y==q) { con=con+5; if(spd>=5) spd=spd-5; else spd=5;
		 		      if(con>490) win();
     p=random(maxx); temp=p%13;  p=p-temp;
     q=random(maxy); temp=q%14;   q=q-temp;
		 		    }
    if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
    if(a==2)  y =  y+14; if(y>maxy) y=0;
    if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
    if(a==4)  x =  x+13; if(x>maxx) x=0;
    if(a==0){  y = y+14 ;  x=x+13; }
		 }

 }


check(){
   int a;
   for(a=1;a<con;a++)

if(m[0]==m[a] && n[0]==n[a]) end();
   else continue;

   }
end()

{

    int j,i;
   setcolor(WHITE);
   for(i=0;i<5;i++){
   delay(500);
    cleardevice();
    delay(500);
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }

		 }

    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    getch();
    getch();
    exit(0);
    }

win()
{
int j,i;
setcolor(WHITE);
   for(i=0;i<5;i++){
   for(j=0;j<=con;j++){
		   setfillstyle(SOLID_FILL,con);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }
    delay(500);
    cleardevice();
    delay(500);
		 }
  settextstyle(3,0,4);
  outtextxy(210,320," YOU WIN ");
  getch();
  exit(0);
}
