#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int s[MAX] = {-1};
int top = -1;

int isFull(int top);
int isEmpty(int top);
int peek(int s[], int top);
void pop();
void push(int value);
void display();

int main()
{
	int val = 0;

	while (!isFull(top))
	{
		printf("Enter value to add: ");
		scanf("%d", &val);
			
		if (val == -1)
			break;

		else if (val == -2)
			pop();	

		else
			push(val); 	
	}

	display();
	
	return 0;
}

int isFull(int top)
{
	if (top == MAX)
		return 1;
	else 
		return 0;
}

int isEmpty(int top)
{
	if (top == -1)
		return 1;
	else 
		return 0;
}

int peek(int s[], int top)
{
	return s[top];
}

void push(int value)
{
	if (!isFull(top))
	{
		s[++top] = value;
		printf("Success %d\n", top);
	}
	else
	{
		printf("Stack is Full.\n"); 
		exit(0);
	}
}

void pop()
{
	if (isEmpty(top))
		printf("The stack is already empty.\n");
	else
		s[top--] = -1;
}

void display()
{
	int i = 0; 
	while (i <= top)
	{
		printf("%d\t", s[i++]);
	}
	printf("\n");
}
