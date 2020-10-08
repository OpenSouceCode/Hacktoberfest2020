//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#define MAXSIZE 3
//
//void push();
//int pop();
//void display();
//
//int stack[MAXSIZE];
//int top=-1;
//
//void main()
//{
//
//    int numChoice;
//    char chChoice;
//
//    do
//    {
//        printf("[ STACK SIZE : %d  |  MAX SIZE : %d ]\n\n",top+1,MAXSIZE);
//        printf("            [MENU] \n1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT \n");
//        printf("SELECT: ");
//        scanf("%d",&numChoice);
//        switch(numChoice)
//        {
//            case 1: push(); break;
//            case 2: printf("%d was popped",pop()); break;
//            case 3: display(); break;
//            case 4: exit(0);
//            default: printf("invalid choice \n \n \n"); main();
//        }
//
//        printf("Do you want to continue? ([y]/n): ");
//        fflush(stdin);
//        scanf("%c",&chChoice);
//
//        printf("\n \n \n");
//    }
//    while(chChoice=='Y' || chChoice=='y');
//    getch();
//    exit(0);
//
//}
//
//void push()
//{
//    if(top>=MAXSIZE-1)
//    {
//        printf("The Stack is FULL\n\n \n");
//        getch();
//        main();
//    }
//    else
//    {
//        top++;
//        int item;
//        printf("Enter element to push: ");
//        scanf("%d",&item);
//        stack[top]=item;
//
//
//    }
//}
//
//int pop()
//{
//    int item;
//    if(top<0){
//        printf("The Stack is EMPTY\n\n \n");
//        getch();
//        main();
//    }
//    else
//    {
//
//        item=stack[top];
//        //stack[top]=NULL;
//        top--;
//    }
//    return item;
//
//}
//
//void display()
//{
//    if(top==-1)
//    {
//        printf("The Stack is EMPTY\n\n \n");
//        getch();
//        main();
//    }
//    else
//    {
//        int i;
//        for(i=top; i>=0; i--)
//        {
//        printf("%d\n", stack[i]);
//        }
//    }
//}
#include<stdio.h>

#include<stdlib.h>
#define MAXSIZE 3

void push();
int pop();
void display();

int stack[MAXSIZE];
int top=-1;

void main()
{

    int numChoice;
    char chChoice;

    do
    {
        printf("            [MENU] \n1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT \n");
        printf("SELECT: ");
        scanf("%d",&numChoice);
        switch(numChoice)
        {
            case 1: push(); break;
            case 2: printf("%d was popped\n",pop()); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("invalid choice \n  \n"); main();
        }

        printf("Do you want to continue? ([y]/n): ");
        fflush(stdin);
        scanf(" %c",&chChoice);
        printf("\n  \n");
    }
    while(chChoice=='Y' || chChoice=='y');

    exit(0);

}

void push()
{
    if(top>=MAXSIZE-1)
    {
        printf("The Stack is FULL\n\n");
        main();
    }
    else
    {
        top++;
        int item;
        printf("Enter element to push: ");
        scanf("%d",&item);
        stack[top]=item;


    }
}

int pop()
{
    int item;
    if(top<0){
        printf("The Stack is EMPTY\n \n");
        main();
    }
    else
    {

        item=stack[top];
        //stack[top]=NULL;
        top--;
    }
    return item;

}

void display()
{
    if(top==-1)
    {
        printf("The Stack is EMPTY\n\n");
        main();
    }
    else
    {
        int i;
        for(i=top; i>=0; i--)
        {
        printf("%d\n", stack[i]);
        }
    }
}
