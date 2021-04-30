//FUNCTIONS

#include "LL.h"

int read()
{
	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	return value; 
}

struct node *create(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	
	assert(newnode != NULL);

	newnode->val = value;
	newnode->next = NULL;

	return newnode;
}

struct node *insert(struct node *h, int value)
{
	struct node *newnode = create(value); 
	
	if (h != NULL)
	{
		struct node *t = h;

		while (t->next != NULL)
			t = t->next;

		t->next = newnode;	
	}

	else
		h = newnode;

	return h;	
}

//Creating a list

struct node *list(struct node *h)
{
	while (1)
	{
		int no;
		no = read();
		
		if (no != -1)
		{
			h = insert(h, no);
		}

		else 
			break;
	}

	return h;
}

//Reverse a singly linked list
struct node *Reverse(struct node *h)
{
	struct node *temp = NULL;
//Single element
	if (h->next == NULL);

//Two elements
	else if ((h->next)->next == NULL)
	{
		temp = h;
		h = h->next;
		(h->next) = temp;
		temp->next = NULL;
		
	}

	else if (h != NULL)
	{
		int count = 1;

		struct node *tail = NULL;
		struct node *cur = h;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}

		tail = cur;

		struct node *prev = NULL;
		while (h != tail)
		{
			count = 1;
			prev = h;
			temp = prev;
			cur = h->next;
		
			if (count == 1)
			{
				h = h->next;
			}

			while (temp != tail)
			{
				if (cur != NULL)
					cur = cur->next;
				
				temp = temp->next = prev->next;
				temp->next = prev;
				prev->next  = cur;
				
				count++;
			}
		}
	}

	return h;
}

void display(struct node *h)
{
	while (h != NULL)
	{
		printf("%3d", (h->val));
		h = h->next;
	}
	printf("  NULL\n");
}