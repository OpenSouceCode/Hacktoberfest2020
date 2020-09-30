//program to convert fully parenthesizes infix expr to posfix expr
//Priyansh Bordia
//19UCS257

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[50];
char pref[50];
char post[50];
int top = -1;
int count = -1;

void pop(void);
void push(char c);
void caculate(int *a, int *b, char ch);
void display();

int main()
{
	printf("Prefix Exp: ");
	scanf("%s", pref);

	for (int i = 0; i < strlen(pref); i++)
	{
		if (pref[i] == '(' || pref[i] == '+' || pref[i] == '-' || pref[i] == '*' || pref[i] == '/') 
		{
			push(pref[i]);
		}

		else if (pref[i] == ')')
		{
			pop();
		}

		else if (isdigit(pref[i]))
		{
			post[++count] = pref[i];
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
		post[++count] = stack[top--];
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
	while (post[i] != '\0')
	{
		printf("%c ", post[i]);
		i++;
	}
	printf("\n");	
}