//FUNCTIONS

#include "linkedlist.h"

struct node
{
	int val;
	struct node *next;
};

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
	
	newnode->val = value;
	newnode->next = NULL;

	return newnode;
}

void insert(struct node **h, struct node **p, int value)
{
	struct node *newnode = create(value); 
	
	if ((*h) == NULL)
		*h = newnode;		
	
	else
		(*p)->next = newnode;	
		
	*p = newnode;
	// count++;
}

//Creating a list

struct node *list(struct node *h)
{
	struct node *t = NULL;
	t = h;

	while (1)
	{
		int no;
		no = read();
		if (no != -1)
		{
			insert(&h, &t, no);
		}
		else 
			break;
	}

	return h;
}

void display(struct node *h)
{
	while (h != NULL)
	{
		printf("%d\t", (h->val));
		h = h->next;
	}
	printf("NULL\n");
}

//Sorting

int isSorted(struct node *h)
{
	struct node *pre = NULL;
	struct node *cur = NULL;

	pre = h;
	cur = h->next;

	int counter = -1;

	while (cur != NULL)
	{
		if (cur->val < pre->val)
		{	
			counter = 0;
			break;
		}
		else 
		{
			counter = 1;
			// continue;
		}

		pre = cur;
		cur = cur->next;
	}

	return counter;
}

struct node *sort(struct node *h)
{
	struct node *pre = NULL;
	struct node *cur = NULL;
	struct node *nxt = NULL;

	if (h->next != NULL)
	{
		while (!isSorted(h))
		{
			pre = NULL;
			cur = h;
			nxt = h->next;

			while (nxt != NULL)
			{
				if (nxt->val < cur->val)
				{
					cur->next = nxt->next;
					nxt->next = cur;
					
					if (h == cur)
					{
						h = nxt; 
					} 

					if (pre != NULL)
						pre->next = nxt;

					pre = nxt;
					nxt = cur->next;
				}

				else 
				{
					pre = cur;
					cur = nxt;
					nxt = nxt->next;
				}
			}
		}
	}
	return h;
}

// merging linked list

struct node *merge(struct node *h, struct node *h1, struct node *h2)
{
	struct node *temp = h;
	struct node *temp1 = h1;
	struct node *temp2 = h2;

	if (temp1->val < temp2->val)
	{
		h = temp1;
		temp1 = temp1->next;
	}

	else
	{ 
		h = temp2;
		temp2 = temp2->next; 
	}
	temp = h;
	// temp = temp->next;

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->val < temp2->val)
		{
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
		// printf("%d ", temp->val);
	}

	if (temp1 == NULL)
	{
		temp->next = temp2;
	}
	else if (temp2 == NULL)
	{
		temp->next = temp1;
	}

	return h;
}
	
struct node *CreateSortedlist(struct node *h)
{
	printf("_________________\n");
	printf("Creating a List\n");
	printf("_________________\n");
	
	h = list(h);
	h = sort(h);

	return h;
} 