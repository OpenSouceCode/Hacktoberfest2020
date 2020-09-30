// conversion of infix expr to postfix expr and evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[50];	
char infix[50];
char postfix[50];
int top = -1;

char pop();
void push(char c);
int prec(char ch);
void evaluate();
void display();

int main()
{
	stack[++top] = '#';
	printf("______________________________________________________\n");
	printf("Enter valid infix expression: ");
	scanf("%s", infix);

	evaluate();
	display();

	return 0;
}

char pop()
{
	return stack[top--];
}

void push(char c)
{
	stack[++top] = c;
}

int prec(char ch)
{
	if (ch == '(')
		return 7;

	else if (ch == '*' || ch == '/' || ch == '%')
		return 5;

	else if (ch == '+' || ch == '-')
		return 3;

	else if (ch == ')')
		return 1;

	else   
		return 0;
}

void evaluate()
{
	int i = 0;
	int j = 0;

	while (infix[i] != '\0')
	{
		if (isalnum(infix[i]))
			postfix[j++] = infix[i];

		else
		{
			if (prec(infix[i]) > prec(stack[top]))
			{
				push(infix[i]);
			}

			else
			{
				while (prec(stack[top]) >= prec(infix[i])) 
					postfix[j++] = pop();
			} 

			
		}

		i++;
	}

	while (stack[top--] != '#') 
		postfix[j++] = pop();

	postfix[j] = '\0';
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