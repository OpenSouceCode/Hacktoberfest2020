// conversion of pully parenthesized infix expr to postfix expr and evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int top = -1;
int count = -1;

void pop(void);
void push(char c);
int calculate(int *a, int *b, char ch);
void display();

int main()
{
	char stack[50];
	
	
	int ans = 0;

	// ans = post[0] - '0';

	printf("Exp evaluates: %d\n", ans);
	return 0;
}

void pop(char s[])
{
	while(s[top] != '(')
	{
		post[++count] = stack[top--];
	}
	top--;
}

void push(char s[], char c)
{
	s[++top] = c;
}

int calculate(int *a, int *b, char ch)
{
	switch (ch)
	{
		case '+': return (*a) + (*b);
			break;

		case '-': return (*a) - (*b);
			break;
		
		case '*': return (*a) * (*b);
			break;

		case '/': return (*a) / (*b);

		default : return 0;
	}

}

void convert(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
		{
			push(s[i]);
		}

		else if (s[i] == ')')
		{
			pop();
		}

		else if (isdigit(s[i]))
		{
			post[++count] = pref[i];
		}

		else
		{
			printf("Invalid Input!!");
			exit(0);
		}
	}
}

void display(char s[])
{
	int  i = 0;
	printf("Postfix Exp: ");
	while (post[i] != '\0')
	{
		printf("%c ", s[i]);
		i++;
	}
	printf("\n");	
}