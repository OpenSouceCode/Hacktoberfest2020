#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
int data;
struct node*next;
} *start= NULL;
void create();
void display();
int  length();
void insertf();
void inserte();
void insertm();
void deletef();
void deletee();
void deletem();
int main (){
  int c,m;
  while(1)
  {

  printf("1.create\n2.Display\n3.length\n4.insert at first\n5.insert at end\n6.insert at middile\n7.Delete at beginning\n8.Delete from end\n9.delete from middile\n10.exit\n");
    scanf("%d",&c);
    switch(c){
    case 1:create();
    break;
    case 2:display();
    break;
    case 3:m=length();
    printf("%d\n",m);
    break;
    case 4:insertf();
    break;
    case 5:inserte();
    break;
    case 6:insertm();
    break;
    case 7:deletef();
    break;
    case 8:deletee();
    break;
    case 9:deletem();
    break;
    case 10:exit(0);
    default:
    printf("out of range");
    break;
}
}
}
void create()
{
   char c;
   struct node *current,*newnode;
   current=(struct node*)malloc(sizeof(struct node));
   
    do{
        printf("enter your data= ");
       newnode=(struct node*)malloc(sizeof(struct node)); scanf("%d",&newnode->data);

        newnode->next=NULL;
        if(start==NULL){
        start=newnode;
        current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;

        }
        printf("do you want do create more node y/n\n");
        c = getch();
       }while(c!='n');
}
void display()
{
  struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=start;
  if(start==NULL)
  printf("linkedlist is empty");
  else
  {
    while(temp->next!=NULL)
    {
      printf("%d-->",temp->data);
      temp=temp->next;

    }
    printf("%d-->",temp->data);
    printf("null\n");
    }
}
int length()
{
  struct node*temp;
 temp=(struct node*)malloc(sizeof(struct node));
  temp=start;
  int c=0;
  while(temp!=NULL)
  {
    c++;
    temp=temp->next;
  }

  return c;
}
void insertf()
{
   struct node *newnode;
   newnode=(struct node*)malloc(sizeof(struct node));

    printf("enter your data= ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(start==NULL)
    start=newnode;
    else
    {
      newnode->next=start;
      start=newnode;
    }
}
void inserte()
{
   struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  temp=(struct node*)malloc(sizeof(struct node));
   temp=start;
    printf("enter your data= ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(start==NULL)
    start=newnode;
    else
    {
      while(temp->next!=NULL){
      temp=temp->next;}
      temp->next=newnode;
    }

}
 void insertm()
 {
   struct node *newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
   temp=(struct node*)malloc(sizeof(struct node));
   temp=start;
    printf("enter your data= ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
   int i=0,pos;
   printf("please enter position at which you want to add(0,1...)=");
   scanf("%d",&pos);
   if(pos>length())
   printf("position is greater than length of linked list");
   else
   {
     while(i!=pos)
     {
       temp=temp->next;
       i++;
     }
     newnode->next=temp->next;
     temp->next=newnode;
   }

 }
 void deletef()
 {
   struct node*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=start;
  if(start==NULL)
  {
    printf("linlked list is empty");
  }
  else{
  start=start->next;}
  free(temp);
 }
void deletee()
{
  struct node*temp,*ptr;
  temp=(struct node*)malloc(sizeof(struct node));
  ptr=(struct node*)malloc(sizeof(struct node));
  temp=start;
  ptr=start;
  if(start==NULL)
  {
    printf("linlked list is empty");
  }
  else
  {
   while(temp->next!=NULL)
   {
     ptr=temp;
     temp=temp->next;

   }
   ptr->next=NULL;
   free(temp);
  }
}
void deletem()
{
  struct node*temp,*ptr;
  temp=(struct node*)malloc(sizeof(struct node));
  ptr=(struct node*)malloc(sizeof(struct node));
  temp=start;
  ptr=start;
  int i=0,pos;
  printf("enter position at you want to delete(0,1..)=");
  scanf("%d",&pos);
if(pos>length())
{
  printf("position is greater than array size");
}
else
{
 while(i!=pos)
 {
   ptr=temp;
   temp=temp->next;
 }
 ptr->next=temp->next;
 free(temp);
}
}
