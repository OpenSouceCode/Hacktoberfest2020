//conversion of infix to postfix expr

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[50];
char infix[50];
char postfix[50];
int top = -1;
int count = -1;

void pop(void);
void push(char c);
void display();

int main()
{
	printf("Prefix Exp: ");
	scanf("%s", infix);

	int i = -1;
	while (infix[++i] != '\0')
	{
		if (infix[i] == '(' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') 
		{
			push(infix[i]);
		}

		else if (infix[i] == ')')
		{
			pop();
		}

		else if (isdigit(infix[i]))
		{
			postfix[++count] = infix[i];
		}

		else
		{
			printf("Invalid Input!!");
			exit(0);
		}
	}

	display();
	return 0;
}

void pop(void)
{
	while(stack[top] != '(')
	{
		postfix[++count] = stack[top--];
	}
	top--;
}

void push(char c)
{
	stack[++top] = c;
}

void display()
{
	int  i = 0;
	printf("Postfix Exp: ");
	while (postfix[i] != '\0')
	{
		printf("%c ", postfix[i]);
		i++;
	}
	printf("\n");	
}