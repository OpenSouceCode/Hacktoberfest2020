// FUNCTIONS

#define MAX 3

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

void push(int s[], int top, int value)
{
	if (!isFull(top))
	{
		s[++top] = value;
		printf("Success\n");
	}
	else
	{
		printf("Stack is Full.\n"); 
		exit(0);
	}
}

void pop(int s[], int top)
{
	if (isEmpty(top))
		printf("The stack is already empty.\n");
	else
		s[top--] = -1;
}

void display(int s[], int top)
{
	int i = 0; 
	while (i <= top)
	{
		printf("%d\t", s[i++]);
	}
	printf("\n");
}