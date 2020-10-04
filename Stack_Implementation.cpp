#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void push(struct node **,int);
int pop(struct node **);
void display(struct node **);
int main()
{
    int num,ch,element;
    struct node *start=NULL;
    while(1)
    {
        system("CLS");
        cout<<"MENU\n-----\n(1) PUSH\n(2) POP\n(3) DISPLAY\n(4) EXIT\n\nENTER CHOICE : ";
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<"Enter element to enter : ";
                cin>>num;
                push(&start,num);
                cout<<"Entered element successfully...Press any key.";
                getch();
                break;
        case 2: element=pop(&start);
                if(element!=NULL)
                    cout<<"Deleted element : "<<element;
                else
                    cout<<"EMPTY STACK......POP operation failed !";
                getch();
                break;

        case 3: cout<<endl;
                display(&start);
                getch();
                break;

        case 4: exit(0);
        default: cout<<"Wrong choice....Try again....";
                 getch();

        }
    }
    return 0;
}

void push(struct node **start,int num)
{
    struct node *temp=*start;
    struct node *neww=new struct node;
    neww->data=num;
    neww->next=NULL;
    if(*start==NULL)
        *start=neww;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=neww;
    }

}
int pop(struct node **start)
{
    int t;
    struct node *temp=*start,*prev=*start;
    if(*start==NULL)
        return NULL;
    else
    {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
            prev->next=NULL;
            t=temp->data;
            if(temp==*start)
                *start=NULL;
            free(temp);
            return t;
    }

}
void display(struct node **start)
{
    int t;
    t=pop(start);
    if(t==NULL)
        return;
    else
    {
        cout<<"| "<<t<<" |"<<endl;
        display(start);
        push(start,t);
    }

}
