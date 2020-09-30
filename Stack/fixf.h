char stack[50];

void pop(char s[])
{
	while(stack[top] != '(')
	{
		s[++count] = stack[top--];
	}
	top--;
}

void push(char c)
{
	stack[++top] = c;
}

void display(char s[])
{
	int  i = 0;
	printf("Postfix Exp: ");
	while (s[i] != '\0')
	{
		printf("%c ", s[i]);
		i++;
	}
	printf("\n");	
}