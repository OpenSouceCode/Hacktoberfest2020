#include <stdio.h>
#include <stdlib.h>

struct node *create(int value);
void insert(struct node **h, struct node **p, int value);
void display(struct node *h);

struct node
{
	int val;
	struct node *next;
};

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;

	int value = 0;
	while (1)
	{
		printf("Enter number: ");
		scanf("%d", &value);
		
		if (value != -1)
			insert(&head, &temp, value);		
		else 
			break;
	}

	temp = head;
	display(temp);

	printf("\n");
	return 0;
	
}

struct node *create(int value)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->val = value;
	newnode->next = NULL;

	return newnode;

}

void insert(struct node **h, struct node **p, int value)
{

	struct node *newnode = NULL;
	newnode = create(value); 
	
	if ((*h) != NULL)
	{
		(*p)->next = newnode;	
	}
	else
	{
		*h = newnode;	
	}
		
	*p = newnode;
	
}

void display(struct node *h)
{
	while (h != NULL)
	{
		printf("%d\t", (h->val));
		h = h->next;
	}
	printf("NULL");
}