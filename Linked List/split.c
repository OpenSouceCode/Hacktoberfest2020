// program to split two linked list by index

#include <stdio.h>
#include <stdlib.h>

int count = 0; 

struct node
{
	int val;
	struct node *next;
};

int read();
struct node *create(int value);
void insert(struct node **h, struct node **p, int value);
void display(struct node *h);

int main()
{
	struct node *head = NULL;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;

	while (1)
	{
		int no;
		no = read();
		if (no != -1)
		{
			insert(&head, &temp, no);
		}
		else 
			break;
	}

	temp = temp1 = head1 = head;
	temp2 = head2 = head->next;
	
	if (head->next != NULL)
		temp = temp2->next;
	else 
		temp = NULL;
	
	int i = 3;
	while (i <= count) //&& temp->next != NULL)
	{
		
		if (i % 2 == 0)
		{
			temp2->next = temp;
			temp2 = temp2->next;
		}
	 	
		else 
		{
			temp1->next = temp;
			temp1 = temp1->next;
		}
		
		temp = temp->next;
		i++;
	}

	temp1->next = NULL;
	display(head1);

	if (head->next != NULL)
		temp2->next = NULL;
	
	display(head2);

	return 0;
}

int read()
{
	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	return value; 
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
	count++;
}

void display(struct node *h)
{
	printf("List:  ");
	while (h != NULL)
	{
		printf("%d   ", (h->val));
		h = h->next;
	}
	printf("NULL\n");
}